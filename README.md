SparkFun LSM9DS0 Linux embedded Library
======================

[![Breakout Board ISO](https://cdn.sparkfun.com//assets/parts/9/3/1/9/12636-01.jpg)](https://www.sparkfun.com/products/12636)

_[LSM9DS0 Breakout Board (SEN-12636)](https://www.sparkfun.com/products/12636)_

This is a breakout board for [ST Micro's LSM9DS0](http://www.st.com/web/catalog/sense_power/FM89/SC1448/PF258556) -- a 3D accelerometer, gyroscope, and magnetometer.

Repository Contents
-------------------
* **/examples** - An example program an a Makefile to easily build your test app.
* **i2c_manager.h/cpp** - A generic linux i2c device manager.
* **LSM9DS0.h/cpp** - The sensor specific implementation.

Usage Guide
------------
First of all you have to activate the i2c adaptor on your embedded computer. [Here](https://learn.sparkfun.com/tutorials/raspberry-pi-spi-and-i2c-tutorial)'s a guide that shows you how to do just that.

Before compiling you need to download and install the i2c-bus driver. The easiest way to do it if you are in a Debian based system (like Raspbian) is:

```bash
sudo apt-get install i2c-tools
```
Which apart from the driver comes with some useful tools (like `i2cdetect`, `i2cget` or `i2cset`).

Then you just need to navigate to the examples folder and type: `make`

```bash
cd examples
make
```
Connect your sensor and do:

```bash
./imu-sensor-lecture
```

you will get the lectures from the sensor printed on stdout

Original Documentation
--------------

* **[Product Repository](https://github.com/sparkfun/LSM9DS0_Breakout)** - Main repository (including hardware files) for the LSM9DS0 Breakout.
* **[Hookup Guide](https://learn.sparkfun.com/tutorials/lsm9ds0-hookup-guide)** - Basic hookup guide for the LSM9DS0 Breakout.

Products that use this Library
---------------------------------

* [LSM9DS0 Breakout Board (SEN-12636)](https://www.sparkfun.com/products/12636)- LSM9DS0 Breakout board.

Version History
---------------
Modified
* V 1.0.2b Porting to Linux embedded system - 28 november 2016

Original
* [V 1.0.2](https://github.com/sparkfun/SparkFun_LSM9DS0_Arduino_Library/releases/tag/V_1.0.2) -- Fixed bug in setAccelABW() function.
* [V 1.0.1](https://github.com/sparkfun/SparkFun_LSM9DS0_Arduino_Library/releases/tag/V_1.0.1) -- Updated library.properties and standardized example names.
* [V 1.0.0](https://github.com/sparkfun/SparkFun_LSM9DS0_Arduino_Library/releases/tag/V_1.0.0) -- Initial commit of Arduino 1.6-compatible library.

License Information
-------------------

This product is _**open source**_!

The original **code** is beerware; if you see Jim (or any other SparkFun employee) at the local, and you've found our code helpful, please buy them a round!

The modified **code** is pizza-birraware (a variation of the original one), se un giorno se beccamo mi offri un pezzo di pizza <%).. e un paio di birre.

Please use, reuse, and modify these files as you see fit. Please maintain attribution to SparkFun Electronics, and Bruno Laurencich and release anything derivative under the same license.

Distributed as-is; no warranty is given.

Bruno and your friends at SparkFun.
