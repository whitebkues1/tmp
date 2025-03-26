/*
 * ina232.c
 *
 *  Created on: Mar 26, 2025
 *      Author: zx
 */

#include "ina232.h"

float INA232_getBusV(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	return (INA232_getBusVReg(I2CHandler, DevAddress));
}

float INA232_getCurrent(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	return (INA232_getCurrentReg(I2CHandler, DevAddress)*INA232_POWERLSB_INV_mA);
}

float INA232_getPower(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	return (INA232_getPowerReg(I2CHandler, DevAddress)*INA232_POWERLSB_INV_mA);
}

uint8_t INA232_setConfig(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress, uint16_t ConfigWord)
{
	uint8_t SentTable[3];
	SentTable[0] = INA232_CONFIG;
	SentTable[1] = (ConfigWord & 0xFF00) >> 8;
	SentTable[2] = (ConfigWord & 0x00FF);

	return HAL_I2C_Master_Transmit(I2CHandler, DevAddress, SentTable, 3, INA232_I2CTIMEOUT);
}

uint16_t INA232_getConfig(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	uint8_t SentTable[1] = {INA232_CONFIG};
	uint8_t ReceivedTable[2];

	HAL_I2C_Master_Transmit(I2CHandler,DevAddress, SentTable, 1, INA232_I2CTIMEOUT);
	if (HAL_I2C_Master_Receive(I2CHandler,DevAddress, ReceivedTable, 2, INA232_I2CTIMEOUT) != HAL_OK)
	{
		return 0xFF;
	}
	else
	{
		return ((uint16_t)ReceivedTable[0]<<8 | ReceivedTable[1]);
	}
}

uint16_t INA232_getShuntV(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	uint8_t SentTable[1] = {INA232_SHUNTV};
	uint8_t ReceivedTable[2];

	HAL_I2C_Master_Transmit(I2CHandler,DevAddress, SentTable, 1, INA232_I2CTIMEOUT);
	if (HAL_I2C_Master_Receive(I2CHandler,DevAddress, ReceivedTable, 2, INA232_I2CTIMEOUT) != HAL_OK)
	{
		return 0xFF;
	}
	else
	{
		return ((uint16_t)ReceivedTable[0]<<8 | ReceivedTable[1]);
	}
}

uint16_t INA232_getBusVReg(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	uint8_t SentTable[1] = {INA232_BUSV};
	uint8_t ReceivedTable[2];

	HAL_I2C_Master_Transmit(I2CHandler,DevAddress, SentTable, 1, INA232_I2CTIMEOUT);
	if (HAL_I2C_Master_Receive(I2CHandler,DevAddress, ReceivedTable, 2, INA232_I2CTIMEOUT) != HAL_OK)
	{
		return 0xFF;
	}
	else
	{
		return ((uint16_t)ReceivedTable[0]<<8 | ReceivedTable[1]);
	}
}

uint8_t INA232_setCalibrationReg(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress, uint16_t ConfigWord)
{
	uint8_t SentTable[3];
	SentTable[0] = INA232_CALIB;
	SentTable[1] = (ConfigWord & 0xFF00) >> 8;
	SentTable[2] = (ConfigWord & 0x00FF);

	return HAL_I2C_Master_Transmit(I2CHandler, DevAddress, SentTable, 3, INA232_I2CTIMEOUT);
}

uint16_t INA232_getCalibrationReg(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	uint8_t SentTable[1] = {INA232_CALIB};
	uint8_t ReceivedTable[2];

	HAL_I2C_Master_Transmit(I2CHandler,DevAddress, SentTable, 1, INA232_I2CTIMEOUT);
	if (HAL_I2C_Master_Receive(I2CHandler,DevAddress, ReceivedTable, 2, INA232_I2CTIMEOUT) != HAL_OK)
	{
		return 0xFF;
	}
	else
	{
		return ((uint16_t)ReceivedTable[0]<<8 | ReceivedTable[1]);
	}
}

uint16_t INA232_getPowerReg(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	uint8_t SentTable[1] = {INA232_POWER};
	uint8_t ReceivedTable[2];

	HAL_I2C_Master_Transmit(I2CHandler,DevAddress, SentTable, 1, INA232_I2CTIMEOUT);
	if (HAL_I2C_Master_Receive(I2CHandler,DevAddress, ReceivedTable, 2, INA232_I2CTIMEOUT) != HAL_OK)
	{
		return 0xFF;
	}
	else
	{
		return ((uint16_t)ReceivedTable[0]<<8 | ReceivedTable[1]);
	}
}

uint16_t INA232_getCurrentReg(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	uint8_t SentTable[1] = {INA232_CURRENT};
	uint8_t ReceivedTable[2];

	HAL_I2C_Master_Transmit(I2CHandler,DevAddress, SentTable, 1, INA232_I2CTIMEOUT);
	if (HAL_I2C_Master_Receive(I2CHandler,DevAddress, ReceivedTable, 2, INA232_I2CTIMEOUT) != HAL_OK)
	{
		return 0xFF;
	}
	else
	{
		return ((uint16_t)ReceivedTable[0]<<8 | ReceivedTable[1]);
	}
}

uint16_t INA232_getManufID(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	uint8_t SentTable[1] = {INA232_MANUF_ID};
	uint8_t ReceivedTable[2];

	HAL_I2C_Master_Transmit(I2CHandler,DevAddress, SentTable, 1, INA232_I2CTIMEOUT);
	if (HAL_I2C_Master_Receive(I2CHandler,DevAddress, ReceivedTable, 2, INA232_I2CTIMEOUT) != HAL_OK)
	{
		return 0xFF;
	}
	else
	{
		return ((uint16_t)ReceivedTable[0]<<8 | ReceivedTable[1]);
	}
}

uint8_t INA232_setMaskEnable(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress, uint16_t ConfigWord)
{
	uint8_t SentTable[3];
	SentTable[0] = INA232_MASK;
	SentTable[1] = (ConfigWord & 0xFF00) >> 8;
	SentTable[2] = (ConfigWord & 0x00FF);

	return HAL_I2C_Master_Transmit(I2CHandler, DevAddress, SentTable, 3, INA232_I2CTIMEOUT);
}

uint16_t INA232_getMaskEnable(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	uint8_t SentTable[1] = {INA232_MASK};
	uint8_t ReceivedTable[2];

	HAL_I2C_Master_Transmit(I2CHandler,DevAddress, SentTable, 1, INA232_I2CTIMEOUT);
	if (HAL_I2C_Master_Receive(I2CHandler,DevAddress, ReceivedTable, 2, INA232_I2CTIMEOUT) != HAL_OK)
	{
		return 0xFF;
	}
	else
	{
		return ((uint16_t)ReceivedTable[0]<<8 | ReceivedTable[1]);
	}
}

uint8_t INA232_setAlertLimit(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress, uint16_t ConfigWord)
{
	uint8_t SentTable[3];
	SentTable[0] = INA232_ALERTL;
	SentTable[1] = (ConfigWord & 0xFF00) >> 8;
	SentTable[2] = (ConfigWord & 0x00FF);

	return HAL_I2C_Master_Transmit(I2CHandler, DevAddress, SentTable, 3, INA232_I2CTIMEOUT);
}

uint16_t INA232_getAlertLimit(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress)
{
	uint8_t SentTable[1] = {INA232_ALERTL};
	uint8_t ReceivedTable[2];

	HAL_I2C_Master_Transmit(I2CHandler,DevAddress, SentTable, 1, INA232_I2CTIMEOUT);
	if (HAL_I2C_Master_Receive(I2CHandler,DevAddress, ReceivedTable, 2, INA232_I2CTIMEOUT) != HAL_OK)
	{
		return 0xFF;
	}
	else
	{
		return ((uint16_t)ReceivedTable[0]<<8 | ReceivedTable[1]);
	}
}
