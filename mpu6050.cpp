// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//
//       Author  :   Benjamin Boehmer
//       Filename:   MPU6050.cpp
//       Part of :   IPASS
//
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

#include "mpu6050.hpp"
#include "hwlib.hpp"
#include "adressen.hpp"

mpu6050::mpu6050(hwlib::i2c_bus & bus):
    bus(bus)
    {starting();}

void mpu6050::starting() {
    auto trans = bus.write(MPU_Address);
    trans.write(PWR_MGMT_1);
    trans.write(0x00);
}

int mpu6050::test(){
    bus.write(MPU_Address).write(WHO_AM_I);
    bus.read(MPU_Address).read(dataStore, 2);
    int data = dataStore[0];
    return data;
}

int mpu6050::read(int HIGH_REG,int LOW_REG){
    bus.write(MPU_Address).write(HIGH_REG);
    bus.read(MPU_Address).read(dataStore1, 1);
    bus.write(MPU_Address).write(LOW_REG);
    bus.read(MPU_Address).read(dataStore2, 1);
    int16_t data = int16_t((dataStore1[0] << 8) | dataStore2[0]);
    return data;
}

int mpu6050::getGyrox() {
    return read(GYRO_XOUT_H,GYRO_XOUT_L);
}

int mpu6050::getGyroy(){
    return read(GYRO_YOUT_H,GYRO_YOUT_L);
}

int mpu6050::getGyroz() {
    return  read(GYRO_ZOUT_H,GYRO_ZOUT_L);
}

int mpu6050::getaccelx() {
    return  read(ACCEL_XOUT_H,ACCEL_XOUT_L);
}

int mpu6050::getaccely() {
    return read(ACCEL_YOUT_H,ACCEL_YOUT_L);
}
int mpu6050::getaccelz() {
    return read(ACCEL_ZOUT_H,ACCEL_ZOUT_L);
}

int mpu6050::temperature() {
    return (read(TEMP_OUT_H,TEMP_OUT_L))/340 + 36.53;
}

