#include <stdio.h>

#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_apps_rcm.h"
#include "interrupt.h"
#include "pin.h"
#include "gpio.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"

#if defined(USE_TIRTOS) || defined(USE_FREERTOS) || defined(SL_PLATFORM_MULTI_THREADED)
#include <stdlib.h>
#include "osi.h"
#endif

#include "gpio_if.h"

static unsigned long ulReg[]=
{
    GPIOA0_BASE,
	GPIOA1_BASE,
	GPIOA2_BASE,
    GPIOA3_BASE,
    GPIOA4_BASE
};

unsigned int RESET_Port = 0, PM0_Port = 0, PM1_Port = 0;
unsigned char RESET_Pin, PM0_Pin, PM1_Pin;

#define PM0_IO 12
#define PM1_IO 13
#define RESET_IO 14

void
ADE7880_PowerMode_Set(unsigned char mode)
{
	switch(mode)
	{
	case PSM0:
		GPIO_IF_Set(PM1_IO, PM1_Port, PM1_Pin, 0);
		GPIO_IF_Set(PM0_IO, PM0_Port, PM0_Pin, 1);
		break;
	case PSM1:
		GPIO_IF_Set(PM1_IO, PM1_Port, PM1_Pin, 0);
		GPIO_IF_Set(PM0_IO, PM0_Port, PM0_Pin, 0);
		break;
	case PSM2:
		GPIO_IF_Set(PM1_IO, PM1_Port, PM1_Pin, 1);
		GPIO_IF_Set(PM0_IO, PM0_Port, PM0_Pin, 0);
		break;
	case PSM3:
		GPIO_IF_Set(PM1_IO, PM1_Port, PM1_Pin, 1);
		GPIO_IF_Set(PM0_IO, PM0_Port, PM0_Pin, 1);
		break;
	default:
		GPIO_IF_Set(PM1_IO, PM1_Port, PM1_Pin, 0);
		GPIO_IF_Set(PM0_IO, PM0_Port, PM0_Pin, 1);
		break;
	}
}

unsigned char
ADE7880_PowerMode_Get()
{
	unsigned char PM1_value, PM0_value, mode;

	PM1_value = GPIO_IF_Get(PM1_IO, PM1_Port, PM1_Pin);
	PM0_value = GPIO_IF_Get(PM0_IO, PM0_Port, PM0_Pin);

	mode = (PM1_value << 1) + PM0_value;

	return mode;
}

void
ADE7880_Operation(unsigned char operation)
{
	switch(operation)
	{
	case START:
		GPIO_IF_Set(RESET_IO, RESET_Port, RESET_Pin, 1);
		break;
	case STOP:
		GPIO_IF_Set(RESET_IO, RESET_Port, RESET_Pin, 0);
		break;
	case RESET:
		GPIO_IF_Set(RESET_IO, RESET_Port, RESET_Pin, 0);
		GPIO_IF_Set(RESET_IO, RESET_Port, RESET_Pin, 1);
		break;
	}
}

void
GPIO_IF_Configure()
{

    GPIO_IF_GetPortNPin(PM0_IO, &RESET_Port, &RESET_Pin);
    GPIO_IF_GetPortNPin(PM1_IO, &PM0_Port, &PM0_Pin);
    GPIO_IF_GetPortNPin(RESET_IO, &PM1_Port, &PM1_Pin);
}

void
GPIO_IF_GetPortNPin(unsigned char ucPin, unsigned int *puiGPIOPort, unsigned char *pucGPIOPin)
{
    *pucGPIOPin = 1 << (ucPin % 8);
    *puiGPIOPort = (ucPin / 8);
    *puiGPIOPort = ulReg[*puiGPIOPort];
}


void
GPIO_IF_Set(unsigned char ucPin, unsigned int uiGPIOPort, unsigned char ucGPIOPin, unsigned char ucGPIOValue)
{
    ucGPIOValue = ucGPIOValue << (ucPin % 8);
    MAP_GPIOPinWrite(uiGPIOPort,ucGPIOPin,ucGPIOValue);
}


unsigned char
GPIO_IF_Get(unsigned char ucPin, unsigned int uiGPIOPort, unsigned char ucGPIOPin)
{
    unsigned char ucGPIOValue;
    long lGPIOStatus;

    lGPIOStatus =  MAP_GPIOPinRead(uiGPIOPort,ucGPIOPin);

    ucGPIOValue = lGPIOStatus >> (ucPin % 8);
    return ucGPIOValue;
}


