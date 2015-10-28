#ifndef __I2C_IF_H__
#define __I2C_IF_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define I2C_MRIS_CLKTOUT        0x2
//*****************************************************************************
// I2C transaction time-out value.
// Set to value 0x7D. (@100KHz it is 20ms, @400Khz it is 5 ms)
//*****************************************************************************

#define I2C_TIMEOUT_VAL         0x7D

#define I2C_MASTER_MODE_STD     0
#define I2C_MASTER_MODE_FST     1

#define DEV_ADDR				0x38

#include "registers_def.h"

extern int ADE7880_Read(Register reg, int *data);
extern int ADE7880_Write(Register reg, int data);

extern int I2C_IF_Open(unsigned long ulMode);
extern int I2C_IF_Close();
extern int I2C_IF_Write(unsigned char ucDevAddr,
             unsigned char *pucData,
             unsigned char ucLen,
             unsigned char ucStop);
extern int I2C_IF_Read(unsigned char ucDevAddr,
            unsigned char *pucData,
            unsigned char ucLen);
extern int I2C_IF_ReadFrom(unsigned char ucDevAddr,
            unsigned char *pucWrDataBuf,
            unsigned char ucWrLen,
            unsigned char *pucRdDataBuf,
            unsigned char ucRdLen);

#ifdef __cplusplus
}
#endif

#endif //  __I2C_IF_H__
