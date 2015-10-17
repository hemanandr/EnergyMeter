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
#include "registers.h"

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

typedef enum
{
    POWERED_UP 	= 0,
	INITIALIZED = 1
} states;


int STATE;

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



void IRQ0()
{
	//STATUS0_ClearFlags();

	UART_PRINT("IRQ0\r\n");
    Interrupt_Enable(IRQ0_IO);
}

void IRQ1()
{
	//STATUS1_ClearFlags();

	UART_PRINT("IRQ1\r\n");
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

	//Open I2C Master in Fast Mode

	I2C_IF_Open(I2C_MASTER_MODE_FST);
	//Hold the RESET signal at Low for configuring other GPIO Pins
	ADE7880_Operation(STOP);

	//Set PSM0
	ADE7880_PowerMode_Set(PSM0);

	//Initialize Interrupts
	Interrupt_IF_Init(IRQ0, IRQ1);

	//START the ADE7880
	ADE7880_Operation(START);

	//Set the State to Powered Up
	STATE = POWERED_UP;
}

void ADE7880_Initialize()
{
	//Clear all Status Flags
	/*STATUS1_ClearFlags();
	STATUS0_ClearFlags();

	//Set I2C as the default communcation interface
	Write(CONFIG2, 0x02);

	//Set other CONFIG Registers and other required gains and stuffs as such

	//HSDC Configuration
	*/

	//Set the State to Initialized
	STATE = INITIALIZED;
}

void main()
{
	int data;

	BoardInit();
    PinMuxConfig();

    InitTerm();

    ADE7880_PowerUp();

	UART_PRINT("Alive\r\n");

	while(1){}
	//ADE7880_Read(CHECKSUM, &data);
    //UART_PRINT("0x%x \r\n", data);
    /*ADE7880_Write(0xEC00, 0x06, 1);
    ADE7880_Read(0xEC00, 1, &data);
    UART_PRINT("0x%x \r\n", data);
	*/

}

