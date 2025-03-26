/*
 * ina232.h
 *
 *  Created on: Mar 26, 2025
 *      Author: zx
 */

#ifndef BSP_INA232_INA232_H_
#define BSP_INA232_INA232_H_

#include "main.h"

#ifndef INA232_ADDRESS_mA
#define INA232_ADDRESS_mA	0x80
#endif

#ifndef INA232_ADDRESS_uA
#define INA232_ADDRESS_uA	0x80
#endif

#ifndef INA232_ADDRESS_nA
#define INA232_ADDRESS_nA	0x80
#endif

#define INA232_I2CTIMEOUT		10

#define INA232_CALIB_VAL_mA			1024
#define INA232_CURRENTLSB_mA		0.5F // mA/bit
#define INA232_CURRENTLSB_INV_mA	1/INA232_CURRENTLSB_mA // bit/mA
#define INA232_POWERLSB_INV_mA		1/(INA232_CURRENTLSB_mA*25) // bit/mW

#define INA232_CALIB_VAL_uA			1024
#define INA232_CURRENTLSB_uA		0.5F // mA/bit
#define INA232_CURRENTLSB_INV_uA	1/INA232_CURRENTLSB_uA // bit/mA
#define INA232_POWERLSB_INV_uA		1/(INA232_CURRENTLSB_uA*25) // bit/mW

#define INA232_CALIB_VAL_nA			1024
#define INA232_CURRENTLSB_nA		0.5F // mA/bit
#define INA232_CURRENTLSB_INV_nA	1/INA232_CURRENTLSB_nA // bit/mA
#define INA232_POWERLSB_INV_nA		1/(INA232_CURRENTLSB_nA*25) // bit/mW

#define INA232_CONFIG		0x00 // Configuration Register (R/W)
#define INA232_SHUNTV		0x01 // Shunt Voltage (R)
#define INA232_BUSV			0x02 // Bus Voltage (R)
#define INA232_POWER		0x03 // Power (R)
#define INA232_CURRENT		0x04 // Current (R)
#define INA232_CALIB		0x05 // Calibration (R/W)
#define INA232_MASK			0x06 // Mask/Enable (R/W)
#define INA232_ALERTL		0x07 // Alert Limit (R/W)
#define INA232_MANUF_ID		0x3E // Manufacturer ID (R)

#define INA232_MODE_POWER_DOWN			(0<<0) // Power-Down
#define INA232_MODE_TRIG_SHUNT_VOLTAGE	(1<<0) // Shunt Voltage, Triggered
#define INA232_MODE_TRIG_BUS_VOLTAGE	(2<<0) // Bus Voltage, Triggered
#define INA232_MODE_TRIG_SHUNT_AND_BUS	(3<<0) // Shunt and Bus, Triggered
#define INA232_MODE_POWER_DOWN2			(4<<0) // Power-Down
#define INA232_MODE_CONT_SHUNT_VOLTAGE	(5<<0) // Shunt Voltage, Continuous
#define INA232_MODE_CONT_BUS_VOLTAGE	(6<<0) // Bus Voltage, Continuous
#define INA232_MODE_CONT_SHUNT_AND_BUS	(7<<0) // Shunt and Bus, Continuous

// Shunt Voltage Conversion Time
#define INA232_VSH_140uS			(0<<3)
#define INA232_VSH_204uS			(1<<3)
#define INA232_VSH_332uS			(2<<3)
#define INA232_VSH_588uS			(3<<3)
#define INA232_VSH_1100uS			(4<<3)
#define INA232_VSH_2116uS			(5<<3)
#define INA232_VSH_4156uS			(6<<3)
#define INA232_VSH_8244uS			(7<<3)

// Bus Voltage Conversion Time (VBUS CT Bit Settings[6-8])
#define INA232_VBUS_140uS			(0<<6)
#define INA232_VBUS_204uS			(1<<6)
#define INA232_VBUS_332uS			(2<<6)
#define INA232_VBUS_588uS			(3<<6)
#define INA232_VBUS_1100uS			(4<<6)
#define INA232_VBUS_2116uS			(5<<6)
#define INA232_VBUS_4156uS			(6<<6)
#define INA232_VBUS_8244uS			(7<<6)

// Averaging Mode (AVG Bit Settings[9-11])
#define INA232_AVG_1				(0<<9)
#define INA232_AVG_4				(1<<9)
#define INA232_AVG_16				(2<<9)
#define INA232_AVG_64				(3<<9)
#define INA232_AVG_128				(4<<9)
#define INA232_AVG_256				(5<<9)
#define INA232_AVG_512				(6<<9)
#define INA232_AVG_1024				(7<<9)

#define	INA232_ADCRANGE_81			(0<<12)	// 81.92mV
#define INA232_ADCRANGE_20			(1<<12)	// 20.48mV

// Reset Bit (RST bit [15])
#define INA232_RESET_INACTIVE		(0<<15)
#define INA232_RESET_ACTIVE			(1<<15)


// Mask/Enable Register
#define INA232_MER_SOL				(1<<15) // Shunt Voltage Over-Voltage
#define INA232_MER_SUL				(1<<14) // Shunt Voltage Under-Voltage
#define INA232_MER_BOL				(1<<13) // Bus Voltagee Over-Voltage
#define INA232_MER_BUL				(1<<12) // Bus Voltage Under-Voltage
#define INA232_MER_POL				(1<<11) // Power Over-Limit
#define INA232_MER_CNVR				(1<<10) // Conversion Ready
#define INA232_MER_ERR				(1<<5)	// CRC or ECC error
#define INA232_MER_AFF				(1<<4)  // Alert Function Flag
#define INA232_MER_CVRF				(1<<3)  // Conversion Ready Flag
#define INA232_MER_OVF				(1<<2)  // Math Overflow Flag
#define INA232_MER_APOL				(1<<1)  // Alert Polarity Bit
#define INA232_MER_LEN				(1<<0)  // Alert Latch Enable

#define INA232_MANUF_ID_DEFAULT		0x5449


float INA232_getBusV(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);
float INA232_getCurrent(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);
float INA232_getPower(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);

uint8_t INA232_setConfig(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress, uint16_t ConfigWord);
uint16_t INA232_getConfig(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);
uint16_t INA232_getShuntV(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);
uint16_t INA232_getBusVReg(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);
uint16_t INA232_getPowerReg(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);
uint8_t INA232_setCalibrationReg(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress, uint16_t ConfigWord);
uint16_t INA232_getCalibrationReg(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);
uint16_t INA232_getCurrentReg(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);
uint16_t INA232_getManufID(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);
uint8_t INA232_setMaskEnable(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress, uint16_t ConfigWord);
uint16_t INA232_getMaskEnable(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);
uint8_t INA232_setAlertLimit(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress, uint16_t ConfigWord);
uint16_t INA232_getAlertLimit(I2C_HandleTypeDef *I2CHandler, uint16_t DevAddress);

#endif /* BSP_INA232_INA232_H_ */
