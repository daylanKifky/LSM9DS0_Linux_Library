CC = g++

LIBPATH = ..
CFLAGS = -I $(LIBPATH) -pthread
C11 = -std=c++11

I2C = $(LIBPATH)/i2c_manager
SENSOR = $(LIBPATH)/LSM9DS0

APP = imu-sensor-lecture

all: $(SENSOR).o $(I2C).o
	$(CC) $(C11) $(CFLAGS) $(SENSOR).o $(I2C).o $(APP).cpp -o $(APP)

$(SENSOR).o: $(SENSOR).cpp
	$(CC) $(C11) $(CFLAGS) -c $(SENSOR).cpp -o $(SENSOR).o


$(I2C).o:
	$(CC) $(C11) $(CFLAGS) -c $(I2C).cpp -o $(I2C).o