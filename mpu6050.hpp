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
/// A class with functie to receive data from mpu6050.
class mpu6050 {
private:
    hwlib::i2c_bus & bus;
    uint8_t dataStore[2];
    uint8_t dataStore1[1];
    uint8_t dataStore2[1];


public:
    /// \brief
    /// constructor to give mpu6050 pins.
    mpu6050(hwlib::i2c_bus & bus);

    /// \brief
    /// A function to start the chip.
    /// \details
    /// The function writes 2 adresses the first one is the adress of the chip and the second address is a reset address this resets the chip and makes it ready.
    void starting();

    /// \brief
    /// A function that test if the chip is working.
    /// \details
    /// The function writes a address called WHO_AM_I and this will return a specific hexideciamel.
    int test();

    /// \brief
    /// This function receives the x from the gyroscope.
    /// \details
    /// This function writes to the specific chip and then read the chip to receive the gyrox.
    int getGyroX();

    /// \brief
    /// This function receives the y from the gyroscope.
    /// \details
    /// This function writes to the specific chip and then read the chip to receive the gyroy.
    int getGyroY();

    /// \brief
    /// This function receives the z from the gyroscope.
    /// \details
    /// This function writes to the specific chip and then read the chip to receive the gyroz.
    int getGyroz();

    /// \brief
    /// This function receives the x from the accelerator.
    /// \details
    ///  The function writes to the accel and receives a high and low bits of the x and that turns in a number.
    int getaccelx();

    /// \brief
    /// This function receives the y from the accelerator.
    /// \details
    ///  The function writes to the accel and receives a high and low bits of the y and that turns in a number.
    int getaccely();

    /// \brief
    /// This function receives the z from the accelerator.
    /// \details
    ///  The function writes to the accel and receives a high and low bits of the z and that turns in a number.
    int getaccelz();
};


#endif //V1OOPC_EXAMPLES_mpu6050_HPP
