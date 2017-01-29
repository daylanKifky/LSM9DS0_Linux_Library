#include "i2c_manager.h"
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <cstdint>

//TODELETE
#include <iostream>//cout
#include <errno.h>//error
#include <stdlib.h>//exit


I2C_Device *I2C_Device::mainDevice = nullptr;
I2C_Device *I2C_Device::secDevice = nullptr;

I2C_Device *I2C_Device::getMain(int adapter_nr){
	if (mainDevice != nullptr){
			mainDevice = new I2C_Device(adapter_nr);
			return mainDevice;
		}
	return nullptr;
}

I2C_Device *I2C_Device::getSecondary(int adapter_nr){
	if (secDevice != nullptr){
		secDevice = new I2C_Device(adapter_nr);
		return secDevice;
	}
	return nullptr;
}

i2c_result I2C_Device::init(){
	if ( ( i2c_file = open(i2c_adapter, O_RDWR) ) < 0)
		return ADAPTER_NOT_AVAIBLE;

	// std::cout << "INIT" << std::endl;
	return SUCCESS;
}

void I2CwriteSimpleByte(uint8_t address, uint8_t data){
	// TODO: IMPLEMENT
}

void I2C_io::I2CwriteByte(uint8_t address, uint8_t subAddress, uint8_t data)
{	

	if (ioctl(adapter->get(), I2C_SLAVE, address) < 0){
		perror("Slave device not found");
		exit(1);
	}


	if ( i2c_smbus_write_byte_data(adapter->get(), subAddress, data) < 0){
		perror("Cannot set subAdress to slave device");
		exit(1);
	}

 }

int32_t I2C_io::I2CreadByte(uint8_t address, uint8_t subAddress)
{	
	if (ioctl(adapter->get(), I2C_SLAVE, address) < 0){
		perror("Slave device not found");
		exit(1);
	}


	int32_t data; // `data` will store the register data	 
	if ( ( data = i2c_smbus_read_byte_data(adapter->get(), subAddress) ) < 0 ){
		perror("Can't read from the slave device");
		exit(1);
	}

	return data;                             // Return data read from slave register
}

void I2C_io::I2CreadBytes(uint8_t address, uint8_t subAddress, uint8_t * dest, uint8_t count)
{  	
	if (ioctl(adapter->get(), I2C_SLAVE, address) < 0){
		perror("Slave device not found");
		exit(1);
	}

	//Set the MSb to 1 in order to activate autoincrement on LSM9DS0
	subAddress |= 0x80;

	// i2c_smbus_read_i2c_block_data(int file, __u8 command, __u8 length, __u8 *values)
	if ( i2c_smbus_read_i2c_block_data(adapter->get(), subAddress, count, dest) < 0 ){
		perror("Can't read from the slave device");
		exit(1);
	}
}

#ifdef __TEST_I2C__
int main(int argc, char const *argv[])
{
	// I2C_Device *dev01 = I2C_Device::getMain(1);
	// dev01->init();

	I2C_io inout = I2C_io(I2C_Device::getMain(1));
	inout.init();


	// inout.I2CreadByte(1,1);

	// delete	dev01;
	return 0;
}

#endif