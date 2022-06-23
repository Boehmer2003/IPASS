//
// Created by benja on 22/06/2022.
//
#include "hwlib.hpp"
#include "mpu6050.hpp"
#include "game.hpp"
#include "leds.hpp"
#include <cstdlib>

void game::starting() {
    grid.initialise();
    chip.starting();
    gameover = true;
    punten = 0;
    test = true;
    while (test) {
        if (chip.test() == 0x68) {
            test = false;
        } else {
            hwlib::cout<<"something went wrong with starting the MPU6050";
            test = true;
        }
    }
}


void game::clear_grid() {
    grid.changeLedRGB(doel_x, doel_y, 0, 0, 0);
    grid.changeLedRGB(player_x, player_y, 0, 0, 0);
}

void game::draw_grid() {
    grid.changeLedRGB(doel_x, doel_y, 0, 0, 100);
    grid.changeLedRGB(player_x, player_y, 100, 0, 0);
}


void game::beweeg_doel_y_and_x() {
    int rand();
    if (controle == true) {
        doel_y = (rand() % 8) + 1;
        doel_x = (rand() % 8) + 1;
    }
}

void game::target_controle() {
    if (player_x == doel_x and player_y == doel_y) {
        controle = true;
    } else {
        controle = false;
    }
}


void game::beweeg_player_y_and_x(int& y,int& x) {
    if (x >= 9000) {
        if (player_x == 8) {
            player_x = 0;
        }
        player_x += 1;

    }
    else if (x <= -9000) {
        if (player_x == 1) {
            player_x = 9;
        }
        player_x -= 1;

    }

    if (y >= 9000) {
        if (player_y == 1) {
            player_y = 9;
        }
        player_y -= 1;


    }
    else if (y <= -9000) {
        if (player_y == 8) {
            player_y = 0;
        }
        player_y += 1;

    }
}


void game::games() {
    starting();
    tijd = false;
    while(gameover) {
        if(punten==1 and tijd){
             begin = hwlib::now_us();

        }
        hwlib::wait_ms(300);
        auto x = chip.getaccelx();
        auto y = chip.getaccely();
        clear_grid();

        beweeg_player_y_and_x(y,x);
        raak_controle();
        beweeg_doel_y_and_x();


        draw_grid();


        if (controle == true){
            punten++;
            hwlib::cout<<punten<<hwlib::endl;
            if(punten==1 and tijd == false){
                tijd= true;
            }
        }
        if(punten==10){
            auto eind = hwlib::now_us();
            auto diff =(eind-begin)/1000000;
            hwlib::cout<<diff<<" sec"<<hwlib::endl;
            gameover= false;
        }

        grid.write();
    }
}

