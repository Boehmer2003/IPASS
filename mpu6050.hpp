//
// Created by benjamin on 19/06/2022.
//
#ifndef V1OOPC_EXAMPLES_mpu6050_HPP
#define V1OOPC_EXAMPLES_mpu6050_HPP
#include "hwlib.hpp"

class mpu6050 {
private:
    hwlib::target::pin_oc scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    hwlib::target::pin_oc sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    hwlib::i2c_bus_bit_banged_scl_sda bus2 = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);



    hwlib::i2c_bus & bus;
    uint8_t dataStore[2];
    uint8_t dataStore1[1];
    uint8_t dataStore2[1];
    const uint8_t MPU_Address 	= 0x68;
    const uint8_t PWR_MGMT_1 	= 0x6B;
    const uint8_t WHO_AM_I  	= 0x75;
    const uint8_t ACCEL_XOUT_H 	= 0x3B;
    const uint8_t ACCEL_XOUT_L 	= 0x3C;
    const uint8_t ACCEL_YOUT_H 	= 0x3D;
    const uint8_t ACCEL_YOUT_L 	= 0x3E;
    const uint8_t ACCEL_ZOUT_H 	= 0x3F;
    const uint8_t ACCEL_ZOUT_L 	= 0x40;
    const uint8_t GYRO_XOUT_H  	= 0x43;
    const uint8_t GYRO_XOUT_L  	= 0x44;
    const uint8_t GYRO_YOUT_H  	= 0x45;
    const uint8_t GYRO_YOUT_L  	= 0x46;
    const uint8_t GYRO_ZOUT_H  	= 0x47;
    const uint8_t GYRO_ZOUT_L  	= 0x48;

public:
    mpu6050(hwlib::i2c_bus & bus);
    void starting();
    int test();
    int getGyroX();
    int getGyroY();
    int getGyroz();
    int getaccelx();
    int getaccely();
    int getaccelz();
};


#endif //V1OOPC_EXAMPLES_mpu6050_HPP
