//
// Created by benja on 22/06/2022.
//
/// @file


#ifndef V1OOPC_EXAMPLES_GAME_HPP
#define V1OOPC_EXAMPLES_GAME_HPP
#include "hwlib.hpp"
#include "mpu6050.hpp"
#include "leds.hpp"
class game {
    hwlib::target::pin_oc scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    hwlib::target::pin_oc sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    hwlib::i2c_bus_bit_banged_scl_sda bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
    hwlib::target::pins leds = hwlib::target::pins::d3;
    mpu6050 chip = mpu6050(bus);
    ledGrid grid = ledGrid(8, 8, leds);
    bool tijd = false;
    bool flag = true;
    bool controle= true;
    int begin;
    int punten = 0;
    int doel_x = 1;
    int doel_y = 1;
    int player_x = 4;
    int player_y = 4;

    void starting();
    void clear_grid();
    void draw_grid();
    int beweeg_player_x(int x);
    int beweeg_player_y(int y);
    int beweeg_doel_x();
    int beweeg_doel_y();
    bool doel_controle();
public:
    void games();






};


#endif //V1OOPC_EXAMPLES_GAME_HPP
