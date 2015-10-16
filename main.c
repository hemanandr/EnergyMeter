#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Driverlib includes
#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_common_reg.h"
#include "hw_apps_rcm.h"
#include "rom.h"
#include "rom_map.h"
#include "interrupt.h"
#include "prcm.h"
#include "gpio.h"
#include "utils.h"
#include "uart.h"

// Common interface includes
#include "uart_if.h"
#include "i2c_if.h"
#include "gpio_if.h"
#include "interrupt_if.h"
#include "pinmux.h"

#define APPLICATION_VERSION     "1.1.1"
#define APP_NAME                "I2C Demo"

#define UART_PRINT              Report
#define FOREVER                 1
#define CONSOLE                 UARTA0_BASE
#define FAILURE                 -1
#define SUCCESS                 0
#define RETERR_IF_TRUE(condition) {if(condition) return FAILURE;}
#define RET_IF_ERR(Func)          {int iRetVal = (Func); \
                                   if (SUCCESS != iRetVal) \
                                     return  iRetVal;}

//ADE7880 Specific Constants
#define DEV_ADDR				0x38

typedef enum
{
    POWERED_UP 	= 0,
	INITIALIZED = 1
} states;

typedef enum
{
	STATUS0 	= 0xE502,
	STATUS1 	= 0xE503,
	CONFIG2		= 0xEC01
} registers;

#if defined(ccs)
extern void (* const g_pfnVectors[])(void);
#endif
#if defined(ewarm)
extern uVectorEntry __vector_table;
#endif

static void
BoardInit(void)
{
#ifndef USE_TIRTOS

#if defined(ccs)
    MAP_IntVTableBaseSet((unsigned long)&g_pfnVectors[0]);
#endif
#if defined(ewarm)
    MAP_IntVTableBaseSet((unsigned long)&__vector_table);
#endif
#endif

    MAP_IntMasterEnable();
    MAP_IntEnable(FAULT_SYSTICK);

    PRCMCC3200MCUInit();
}

int STATE;

int
Read(unsigned short address, int length, int *data)
{
	//address 	- to read from ADE7880
	//length	- lenght of the data - number of bytes
	//data		- data located in the requested address

	//Data holders for the I2C Communcation
	unsigned char ucDevAddr, ucRegAddr[2], ucRdLen;
	unsigned char aucRdDataBuf[256];

	//Spit or Convert the values into bytes (unsigned char - 1 byte)
	ucDevAddr = (unsigned char) DEV_ADDR;
	ucRegAddr[0] = (unsigned char) (address>>8);
	ucRegAddr[1] = (unsigned char) address;
	ucRdLen = (unsigned char) length;

	//Write the Register Address to Read
	RET_IF_ERR(I2C_IF_Write(ucDevAddr,ucRegAddr,2,0));

	//Read the Register data to aucRdDataBuf
	RET_IF_ERR(I2C_IF_Read(ucDevAddr, &aucRdDataBuf[0], ucRdLen));

	//Convert data from buffer to value
	*data = (aucRdDataBuf[0] << 24) + (aucRdDataBuf[1] << 16) + (aucRdDataBuf[2] << 8) + (aucRdDataBuf[3]);
	*data = *data >> (32 - (length*8));

	return SUCCESS;
}

int
Write(unsigned short address, int data, int length)
{
	//address 	- to write to ADE7880
	//length	- lenght of the data - number of bytes
	//data		- data to be written

	//Data holders for the I2C Communcation
	unsigned char ucDevAddr, ucStopBit, ucLen;
	unsigned char aucDataBuf[256];

	//Temporarty Variables
	int iRetVal;
	int count;

	//Spit or Convert the values into bytes (unsigned char - 1 byte)
	ucDevAddr = (unsigned char) DEV_ADDR;
	ucLen = (unsigned char) length + 2;
	ucStopBit = (unsigned char) 1;
	aucDataBuf[0] = (unsigned char) (address>>8);
	aucDataBuf[1] = (unsigned char) address;

	//Data value buffered as individual bytes
	for(count = 2; length >= 0; length--, count++)
	{
		aucDataBuf[count] = (unsigned char) (data >> ((length-1) * 8));
	}

	//Write to the data into the given Register
	iRetVal = I2C_IF_Write(ucDevAddr, aucDataBuf, ucLen, ucStopBit);	//TODO Change the iRetVal to RET_IF_ERR()

	return iRetVal;
}

void IRQ0()
{
	//STATUS0_ClearFlags();

	UART_PRINT("IRQ0\n");
    Interrupt_Enable(IRQ0_IO);
}

void IRQ1()
{
	//STATUS1_ClearFlags();

	UART_PRINT("IRQ1\n");
    Interrupt_Enable(IRQ1_IO);

    /*if(STATE == POWER_UP)
    {
    	if(ADE7880_STATUS1(RSTDONE))
    	{
    		ADE7880_Initialize();
    	}
    }*/
}

void ADE7880_PowerUp()
{
	//Initialize the GPIO Pins for RESET, PM0, PM1
	GPIO_IF_Configure();

	//Hold the RESET signal at Low for configuring other GPIO Pins
	ADE7880_Operation(STOP);

	//Set PSM0
	ADE7880_PowerMode_Set(PSM0);

	//Initialize Interrupts

	//START the ADE7880
	ADE7880_Operation(START);

	//Set the State to Powered Up
	STATE = POWERED_UP;
}

void ADE7880_Initialize()
{
	//Clear all Status Flags
	STATUS1_ClearFlags();
	STATUS0_ClearFlags();

	//Set I2C as the default communcation interface
	Write(CONFIG2, 0x02);

	//Set other CONFIG Registers and other required gains and stuffs as such

	//HSDC Configuration

	//Set the State to Initialized
	STATE = INITIALIZED;
}

void main()
{
	//int data;

	BoardInit();
    PinMuxConfig();

    InitTerm();

    ADE7880_PowerUp();
	//Button_IF_Init(IRQ0, IRQ1);

	//UART_PRINT("Alive\n");

    while(1)
    {
    	//Meter_Mode_Set(PSM0);
    }


    /*
    I2C_IF_Open(I2C_MASTER_MODE_FST);


    Read(0xEC00, 1, &data);
    UART_PRINT("0x%x \r\n", data);
    Write(0xEC00, 0x06, 1);
    Read(0xEC00, 1, &data);
    UART_PRINT("0x%x \r\n", data);
	*/

}

