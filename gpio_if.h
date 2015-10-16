#ifndef __GPIOIF_H__
#define __GPIOIF_H__

//*****************************************************************************
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//*****************************************************************************

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
    PSM0 = 0x01,
    PSM1 = 0x00,
    PSM2 = 0x10,
    PSM3 = 0x11
} powerModeNames;

typedef enum
{
	START = 0x00,
	STOP = 0x01,
	RESET = 0x10
} operationNames;

extern void GPIO_IF_GetPortNPin(unsigned char ucPin, unsigned int *puiGPIOPort, unsigned char *pucGPIOPin);

extern void GPIO_IF_Set(unsigned char ucPin,
             unsigned int uiGPIOPort,
             unsigned char ucGPIOPin,
             unsigned char ucGPIOValue);

extern unsigned char GPIO_IF_Get(unsigned char ucPin,
             unsigned int uiGPIOPort,
             unsigned char ucGPIOPin);

extern void GPIO_IF_Configure();

extern unsigned char ADE7880_PowerMode_Get();
extern void ADE7880_Operation(unsigned char operation);
extern void ADE7880_PowerMode_Set(unsigned char mode);

//*****************************************************************************
// Mark the end of the C bindings section for C++ compilers.
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  __GPIOIF_H__

