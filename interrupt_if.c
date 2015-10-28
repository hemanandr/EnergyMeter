#include <stdlib.h>
#include "hw_types.h"
#include "hw_ints.h"
#include "rom.h"
#include "rom_map.h"
#include "gpio.h"
#include "interrupt.h"
#include "pin.h"
#include "hw_memmap.h"
#ifdef SL_PLATFORM_MULTI_THREADED  /* If OS-based application */
#include "osi.h"
#endif
#include "interrupt_if.h"

#define IRQ0_GPIO_BASE	GPIOA0_BASE	//GPIOA2_BASE
#define IRQ0_GPIO_PIN	GPIO_PIN_6	//GPIO_PIN_6
#define IRQ0_INT		INT_GPIOA0	//INT_GPIOA2

#define IRQ1_GPIO_BASE	GPIOA1_BASE	//GPIOA1_BASE
#define IRQ1_GPIO_PIN	GPIO_PIN_5	//GPIO_PIN_5
#define IRQ1_INT		INT_GPIOA1	//INT_GPIOA1

P_INT_HANDLER IRQ0_InterruptHdl;
P_INT_HANDLER IRQ1_InterruptHdl;

void IRQ0_IntHandler()
{
    unsigned long ulPinState =  GPIOIntStatus(IRQ0_GPIO_BASE,1);
    if(ulPinState & IRQ0_GPIO_PIN)
    {
        Interrupt_Disable(IRQ0_IO);
        Interrupt_Disable(IRQ1_IO);

        Interrupt_Enable(IRQ0_IO);
        Interrupt_Enable(IRQ1_IO);

        IRQ0_InterruptHdl();
    }
}

void IRQ1_IntHandler()
{
    unsigned long ulPinState =  GPIOIntStatus(IRQ1_GPIO_BASE,1);

    if(ulPinState & IRQ1_GPIO_PIN)
    {
        Interrupt_Disable(IRQ0_IO);
        Interrupt_Disable(IRQ1_IO);

        Interrupt_Enable(IRQ0_IO);
        Interrupt_Enable(IRQ1_IO);

        IRQ1_InterruptHdl();
    }
}

void Interrupt_IF_Init(P_INT_HANDLER s_IRQ0_InterruptHdl,P_INT_HANDLER s_IRQ1_InterruptHdl )
{
    if(s_IRQ1_InterruptHdl != NULL)
    {
        // Set Interrupt Type for GPIO
        MAP_GPIOIntTypeSet(IRQ1_GPIO_BASE,IRQ1_GPIO_PIN,GPIO_FALLING_EDGE);
        IRQ1_InterruptHdl = s_IRQ1_InterruptHdl;

        // Register Interrupt handler
#if defined(USE_TIRTOS) || defined(USE_FREERTOS) || defined(SL_PLATFORM_MULTI_THREADED)
        osi_InterruptRegister(IRQ1_INT,(P_OSI_INTR_ENTRY)IRQ1_IntHandler, \
                                INT_PRIORITY_LVL_1);
#else
		MAP_IntPrioritySet(IRQ1_INT, INT_PRIORITY_LVL_1);
        MAP_GPIOIntRegister(IRQ1_GPIO_BASE, IRQ1_IntHandler);
#endif

        MAP_GPIOIntClear(IRQ1_GPIO_BASE,IRQ1_GPIO_PIN);
        MAP_GPIOIntEnable(IRQ1_GPIO_BASE,GPIO_INT_PIN_5);
    }

    if(s_IRQ0_InterruptHdl != NULL)
    {
        // Set Interrupt Type for GPIO
        MAP_GPIOIntTypeSet(IRQ0_GPIO_BASE,IRQ0_GPIO_PIN,GPIO_FALLING_EDGE);
        IRQ0_InterruptHdl = s_IRQ0_InterruptHdl;
        
        // Register Interrupt handler
#if defined(USE_TIRTOS) || defined(USE_FREERTOS) || defined(SL_PLATFORM_MULTI_THREADED) 
        osi_InterruptRegister(IRQ0_INT,(P_OSI_INTR_ENTRY)IRQ0_IntHandler, \
                                INT_PRIORITY_LVL_1);
#else
		MAP_IntPrioritySet(IRQ0_INT, INT_PRIORITY_LVL_1);
        MAP_GPIOIntRegister(IRQ0_GPIO_BASE, IRQ0_IntHandler);
#endif    

        MAP_GPIOIntClear(IRQ0_GPIO_BASE,IRQ0_GPIO_PIN);
        MAP_GPIOIntEnable(IRQ0_GPIO_BASE,GPIO_INT_PIN_6);
    }
}

void Interrupt_Enable(unsigned char ucInterrupt)
{
    if(ucInterrupt & IRQ0_IO)
    {
        MAP_GPIOIntClear(IRQ0_GPIO_BASE,IRQ0_GPIO_PIN);
        MAP_IntPendClear(IRQ0_INT);
        MAP_IntEnable(IRQ0_INT);
        MAP_GPIOIntEnable(IRQ0_GPIO_BASE,IRQ0_GPIO_PIN);
    }

    if(ucInterrupt & IRQ1_IO)
    {
         MAP_GPIOIntClear(IRQ1_GPIO_BASE,IRQ1_GPIO_PIN);
         MAP_IntPendClear(IRQ1_INT);
         MAP_IntEnable(IRQ1_INT);
         MAP_GPIOIntEnable(IRQ1_GPIO_BASE,IRQ1_GPIO_PIN);
    }
}

void Interrupt_Disable(unsigned char ucInterrupt)
{
    if(ucInterrupt & IRQ0_IO)
    {
        MAP_GPIOIntDisable(IRQ0_GPIO_BASE,IRQ0_GPIO_PIN);
        MAP_GPIOIntClear(IRQ0_GPIO_BASE,IRQ0_GPIO_PIN);
        MAP_IntDisable(IRQ0_INT);
    }

    if(ucInterrupt & IRQ1_IO)
    {
        MAP_GPIOIntDisable(IRQ1_GPIO_BASE,IRQ1_GPIO_PIN);
        MAP_GPIOIntClear(IRQ1_GPIO_BASE,IRQ1_GPIO_PIN);
        MAP_IntDisable(IRQ1_INT);
    }
}
