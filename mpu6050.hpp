//
// Created by benjamin on 19/06/2022.
//
/// @file

#ifndef V1OOPC_EXAMPLES_mpu6050_HPP
#define V1OOPC_EXAMPLES_mpu6050_HPP
#include "hwlib.hpp"
/// \brief
/// A class to control a the MPU6050 chip.
/// \details
/// A class with
class mpu6050 {
private:
    hwlib::target::pin_oc scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    hwlib::target::pin_oc sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    hwlib::i2c_bus_bit_banged_scl_sda bus2 = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);


    hwlib::i2c_bus & bus;
    uint8_t dataStore[2];
    uint8_t dataStore1[1];
    uint8_t dataStore2[1];


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
