//
// Created by benja on 19/06/2022.
//
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
int mpu6050::getGyroX() {
    bus.write(MPU_Address).write(GYRO_XOUT_H);
    bus.read(MPU_Address).read(dataStore1, 1);
    bus.write(MPU_Address).write(GYRO_XOUT_L);
    bus.read(MPU_Address).read(dataStore2, 1);
    int16_t data = int16_t((dataStore1[0] << 8) | dataStore2[0]);

    return data;
}
int mpu6050::getGyroY(){
    bus.write(MPU_Address).write(GYRO_YOUT_H);
    bus.read(MPU_Address).read(dataStore1, 1);
    bus.write(MPU_Address).write(GYRO_YOUT_L);
    bus.read(MPU_Address).read(dataStore2, 1);
    int16_t data = int16_t((dataStore1[0] << 8) | dataStore2[0]);
    return data;

}
int mpu6050::getGyroz() {
    bus.write(MPU_Address).write(GYRO_ZOUT_H);
    bus.read(MPU_Address).read(dataStore1,1);
    bus.write(MPU_Address).write(GYRO_ZOUT_L);
    bus.read(MPU_Address).read(dataStore2,1);
    int16_t data = int16_t((dataStore1[0] << 8) | dataStore2[0]);
    return data;
}

int mpu6050::getaccelx() {
    bus.write(MPU_Address).write(ACCEL_XOUT_H);
    bus.read(MPU_Address).read(dataStore1,1);
    bus.write(MPU_Address).write(ACCEL_XOUT_L);
    bus.read(MPU_Address).read(dataStore2,1);
    int16_t data = int16_t((dataStore1[0] << 8) | dataStore2[0]);
    return data;


}
int mpu6050::getaccely() {
    bus.write(MPU_Address).write(ACCEL_YOUT_H);
    bus.read(MPU_Address).read(dataStore1, 1);
    bus.write(MPU_Address).write(ACCEL_YOUT_L);
    bus.read(MPU_Address).read(dataStore2, 1);
    int16_t data = int16_t((dataStore1[0] << 8) | dataStore2[0]);
    return data;
}
int mpu6050::getaccelz() {
    bus.write(MPU_Address).write(ACCEL_ZOUT_H);
    bus.read(MPU_Address).read(dataStore1, 1);
    bus.write(MPU_Address).write(ACCEL_ZOUT_L);
    bus.read(MPU_Address).read(dataStore2, 1);
    int16_t data = int16_t((dataStore1[0] << 8) | dataStore2[0]);
    return data;
}