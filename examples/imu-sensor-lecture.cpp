#include <LSM9DS0.h>
#include <i2c_manager.h>

#include <chrono>
#include <thread>

#define WAIT_MILLIS 100

using std::cout;		using std::endl;

int main(int argc, char const *argv[])
{
	//Get an I2C_Device object representing the hardware device on your computer.
	//This class can handle up to 2 different i2c devices, 
	//the adapter number of each one needs to be passed to the factory function
	I2C_Device *device = I2C_Device::getMain(1); 

	// Initialize the I2C hardware.
	device->init();

	//Our inertial mesurement unit
	LSM9DS0 sensor = LSM9DS0(device);

	while(1){
		//Read the sensors. The results are stored in some member variables
		sensor.readGyro();
		sensor.readAccel();
		sensor.readMag();

		//The readings are stored as raw 16-bit signed values.
		//Convert them to real-world units and print them.
		cout 	<< sensor.calcGyro(sensor.gx) << sensor.calcGyro(sensor.gy) << sensor.calcGyro(sensor.gz)
				<< sensor.calcAccel(sensor.ax) << sensor.calcAccel(sensor.ay) << sensor.calcAccel(sensor.az)
				<< sensor.calcMag(sensor.mx) << sensor.calcMag(sensor.my) << sensor.calcMag(sensor.mz)
				<< endl;

		//A delay between readings
		std::this_thread::sleep_for(std::chrono::milliseconds( WAIT_MILLIS ));
	}

	return 0;
}