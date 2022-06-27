// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//
//       Author  :   Benjamin Boehmer
//       Filename:   MPU6050.hpp
//       Part of :   IPASS
//
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

/// @file
// MPU6050 LIBRARY
#ifndef V1OOPC_EXAMPLES_mpu6050_HPP
#define V1OOPC_EXAMPLES_mpu6050_HPP
#include "hwlib.hpp"
#include "Gyroscope.hpp"
#include "accelerometer.hpp"
#include "temperature.hpp"

/// \brief
/// A class to control a the MPU6050 chip.
/// \details
/// A class with functie to receive data from mpu6050.
class mpu6050: public gyroscope, public accelerometer, public temperature_sensor  {
private:
    hwlib::i2c_bus & bus;
    uint8_t dataStore[2];
    uint8_t dataStore1[1];
    uint8_t dataStore2[1];
    bool tester= true;



    /// \brief
    /// A function to start the chip.
    /// \details
    /// The function writes 2 adresses the first one is the adress of the chip and the second address is a reset address this resets the chip and makes it ready.
     void starting();

    /// \brief
    /// This function is to read from a chip.
    /// \details
    /// The function writes and reads for the user the only thing that the user has to givfe is the high- and lowregister.
     int read(int HIGH_REG,int LOW_REG);
public:
    /// \brief
    /// the constructor for the class to give the class the right pins.
    /// \details
    /// Gives the scl and sda as a bus
    mpu6050(hwlib::i2c_bus & bus);



    /// \brief
    /// A function that test if the chip is working.
    /// \details
    /// The function writes a address called WHO_AM_I and this will return a specific hexideciamel.
    int test();

    /// \brief
    /// This function receives the x from the gyroscope.
    /// \details
    /// This function writes to the specific chip and then read the chip to receive the gyrox.
    int getGyrox() override;

    /// \brief
    /// This function receives the y from the gyroscope.
    /// \details
    /// This function writes to the specific chip and then read the chip to receive the gyroy.
    int getGyroy() override;

    /// \brief
    /// This function receives the z from the gyroscope.
    /// \details
    /// This function writes to the specific chip and then read the chip to receive the gyroz.
    int getGyroz() override;

    /// \brief
    /// This function receives the x from the accelerator.
    /// \details
    ///  The function writes to the accel and receives a high and low bits of the x and that turns in a number.
    int getaccelx() override;

    /// \brief
    /// This function receives the y from the accelerator.
    /// \details
    ///  The function writes to the accel and receives a high and low bits of the y and that turns in a number.
    int getaccely() override;

    /// \brief
    /// This function receives the z from the accelerator.
    /// \details
    ///  The function writes to the accel and receives a high and low bits of the z and that turns in a number.
    int getaccelz() override;

    /// \brief
    /// This function returns the temperature around the chip.
    /// \details
    /// The function writes to the temperature and receives the temperature around the chip.
    int temperature() override;
};


#endif //V1OOPC_EXAMPLES_mpu6050_HPP
