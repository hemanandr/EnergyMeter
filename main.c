#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
#include "registers_def.h"

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

void ADE7880_ClearFlags(Register reg)
{
	int flags;

	ADE7880_Read(reg, &flags);
	ADE7880_Write(reg, flags);
}

void ADE7880_SetValue(Register reg, int bit, bool value)
{
	int data;
	unsigned short bitPos;

	bitPos = BitPosition(bit);

	data = ADE7880_Read(reg, &data);
	data = data & (~bit);

	value = value << bitPos;

	data = data | value;

	ADE7880_Write(reg, data);
}

int ADE7880_GetValue(Register reg, int bit)
{
	int data;
	unsigned short bitPos;

	bitPos = BitPosition(bit);

	data = ADE7880_Read(reg, &data);
	data = data & bit;

	data = data >> bitPos;

	return data;
}

void ADE7880_Initialize()
{
	//Clear all Status Flags
	ADE7880_ClearFlags(STATUS0);
	ADE7880_ClearFlags(STATUS1);

	//Set I2C as the default communcation interface
	ADE7880_Write(CONFIG2, 0x02);

	//Set other CONFIG Registers and other required gains and stuffs as such
	//Intialize Gain Registers to a Gain of 1
	ADE7880_SetValue(Gain, PGA1 | PGA2 | PGA3, 0x0000);

	//Set the State to Initialized
	STATE = INITIALIZED;
}

void IRQ0()
{
	int status;

	ADE7880_Read(STATUS0, &status);
    ADE7880_ClearFlags(STATUS0);

}

void IRQ1()
{
	int status;

	ADE7880_Read(STATUS1, &status);

	if(status & RSTDONE)	ADE7880_Initialize();


	ADE7880_ClearFlags(STATUS1);
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


void main()
{
	BoardInit();
    PinMuxConfig();

    InitTerm();

    ADE7880_PowerUp();

	while(1)
	{

	}

}

