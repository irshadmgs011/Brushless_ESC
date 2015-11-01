/*!
***     \file	  SPI_slave.c
***     \ingroup  SPI_slave
***     \author   Daniel
***     \date	  9/26/2015 6:51:00 PM
***     \brief    TODO
***
******************************************************************************/

/* Header file guard symbol to prevent multiple includes */
#ifndef SPI_slave_H_
#define SPI_slave_H_

/* storage class specifier if used with C++ */
#ifdef  __cplusplus
  extern "C" {
#endif

/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/
#include <stdbool.h>
/*=============================================================================
=======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
=============================================================================*/
#define SPI_NUM_CMDS 12

typedef enum SPI_Cmd_e
{
	SPI_CMD_TO_FBL = 0xA0,
	SPI_CMD_SET_CONFIG = 0x20,
	SPI_CMD_GET_CONFIG = 0x21,
	SPI_CMD_SAVE_CONFIG = 0x22,
	SPI_CMD_ARM = 0x30,
	SPI_CMD_SET_THROTTLE = 0x31,
	SPI_CMD_GET_THROTTLE = 0x32,
	SPI_CMD_GET_PPM = 0x33,
	SPI_CMD_GET_STATUS = 0x40,
	SPI_CMD_GET_ERRORS = 0x41
}SPI_Cmd_t;

typedef struct SPI_Cmd_Data_s
{
	SPI_Cmd_t cmd;
	uint8_t paramLen;
	uint8_t resultLen;
}SPI_Cmd_Data_t;

/*=============================================================================
=======                       CONSTANTS  &  TYPES                       =======
=============================================================================*/

/*=============================================================================
=======                              EXPORTS                            =======
=============================================================================*/
void SPI_SlaveInit(void);
void SPI_SetTransmitBuffer(uint8_t bufLen, void *data);
bool SPI_Cmd_Callback(uint8_t cmd, volatile void *param, uint8_t paramLen);

/* end of storage class specifier if used with C++ */
#ifdef  __cplusplus
}
#endif

#endif /*SPI_slave_H_*/
/* EOF */