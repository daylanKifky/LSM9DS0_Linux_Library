/**
 * @file i2c_manager.h
 * Handler classes for Linux i2c adapter.
 * This file contains the hardware implementationfor the i2c communication,
 *
 */
#ifndef __I2C_MANAGER_H_
#define __I2C_MANAGER_H_

#include <cstdint>
#include <stdio.h>

#include <iostream>

/**
 * Possible results of an i2c opperation
 */
enum i2c_result{
	SUCCESS = 0, 
	ADAPTER_NOT_AVAIBLE, ///< The requested i2c adapter is not avaible on this machine. 
	READ_ERROR, ///< Can't read from the slave device. Are you asking for the right register?
	WRITE_ERROR,	///< Can't write to the slave device. Are you asking for the right register?
	DEVICE_NOT_FOUND ///< Can't find the device. 
	///< Can be due to an error on the configuration files, \n 
	///< a physical connectivity problem (some lousy wires), \n
};

/**
 * Represents a i2c hardware device handled from user space through an adapter
 * It's implemented as a dobleton which returns only two intances, no more than one time
 *
 * @TOREIMPLEMENT Perhaps this is too complicated for no reason? 
 */
class I2C_Device{
public:
	int get(){return i2c_file;};

	const char *getAdapter() const {return i2c_adapter;};

	I2C_Device (const I2C_Device& ) = delete;
	I2C_Device& operator=(const I2C_Device&) = delete;

	static I2C_Device *getMain(int adapter_nr);
	static I2C_Device *getSecondary(int adapter_nr);

	/// Initialize the I2C hardware.
	i2c_result init();

private:

	I2C_Device(int adapter_nr)
	{
		// i2c_adapter stores the device file name of the i2c interface
		snprintf(i2c_adapter, 19, "/dev/i2c-%d", adapter_nr);
	};


	int i2c_file;
	char i2c_adapter[20];
	static I2C_Device *mainDevice;
	static I2C_Device *secDevice;
};

class I2C_io {
public:
	I2C_io(I2C_Device *_adapter):
	adapter(_adapter)
	{};

	
private:
	I2C_Device *adapter;

protected:

	// I2CwriteSimpleByte() -- Write a byte out of I2C directly into the device (no register set)
	// Input:
	//	- address = The 7-bit I2C address of the slave device.
	//	- data = Byte to be written to the register.
	void I2CwriteSimpleByte(uint8_t address, uint8_t data);

	// I2CwriteByte() -- Write a byte out of I2C to a register in the device
	// Input:
	//	- address = The 7-bit I2C address of the slave device.
	//	- subAddress = The register to be written to.
	//	- data = Byte to be written to the register.
	void I2CwriteByte(uint8_t address, uint8_t subAddress, uint8_t data);
	
	// I2CreadByte() -- Read a single byte from a register over I2C.
	// Input:
	//	- address = The 7-bit I2C address of the slave device.
	//	- subAddress = The register to be read from.
	// Output:
	//	- The byte read from the requested address. (returned as a 32bit signed in order to match the SMBus return type)
	int32_t I2CreadByte(uint8_t address, uint8_t subAddress);
	
	// I2CreadBytes() -- Read a series of bytes, starting at a register via I2C
	// Input:
	//	- address = The 7-bit I2C address of the slave device.
	//	- subAddress = The register to begin reading.
	// 	- * dest = Pointer to an array where we'll store the readings.
	//	- count = Number of registers to be read.
	// Output: No value is returned by the function, but the registers read are
	// 		all stored in the *dest array given.
	void I2CreadBytes(uint8_t address, uint8_t subAddress, uint8_t * dest, uint8_t count);
	
	
};


class spi_io{
protected:
	////////////////////////////////////////
	//    SPI     NOT YET IMPLEMENTED!!   //
	////////////////////////////////////////
	// initSPI() -- Initialize the SPI hardware.
	// This function will setup all SPI pins and related hardware.
	// void initSPI();
	
	// // SPIwriteByte() -- Write a byte out of SPI to a register in the device
	// // Input:
	// //	- csPin = The chip select pin of the slave device.
	// //	- subAddress = The register to be written to.
	// //	- data = Byte to be written to the register.
	// void SPIwriteByte(uint8_t csPin, uint8_t subAddress, uint8_t data);
	
	// // SPIreadByte() -- Read a single byte from a register over SPI.
	// // Input:
	// //	- csPin = The chip select pin of the slave device.
	// //	- subAddress = The register to be read from.
	// // Output:
	// //	- The byte read from the requested address.
	// uint8_t SPIreadByte(uint8_t csPin, uint8_t subAddress);
	
	// // SPIreadBytes() -- Read a series of bytes, starting at a register via SPI
	// // Input:
	// //	- csPin = The chip select pin of a slave device.
	// //	- subAddress = The register to begin reading.
	// // 	- * dest = Pointer to an array where we'll store the readings.
	// //	- count = Number of registers to be read.
	// // Output: No value is returned by the function, but the registers read are
	// // 		all stored in the *dest array given.
	// void SPIreadBytes(uint8_t csPin, uint8_t subAddress, 
	// 						uint8_t * dest, uint8_t count);
	
};

#endif
