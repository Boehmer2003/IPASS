//
// Created by benja on 22/06/2022.
//
#include "game.hpp"
#include <cstdlib>


game::game( mpu6050 & chips):
        chip(chips)
        {}


void game::starting() {
    grid.initialise();
    gameover = false;
    punten = 0;
    test = true;
    while (test) {
        if (chip.test() == 0x68) {
            test = false;
        } else {
            hwlib::cout<<"something went wrong with starting the MPU6050"<<hwlib::endl;
            test = true;
        }
    }
    grid.changeLedRGB(powerupx, powerupy, 0, 100, 0);
}


void game::clear_grid() {
    grid.changeLedRGB(doel_x, doel_y, 0, 0, 0);
    grid.changeLedRGB(player_x, player_y, 0, 0, 0);
    grid.changeLedRGB(powerupx, powerupy, 0, 0, 0);

}

void game::draw_grid() {

    grid.changeLedRGB(doel_x, doel_y, 100, 0, 0);
    grid.changeLedRGB(player_x, player_y, 0,0, 100);
    if (((hwlib::now_us()-begin_powerup_time)/ 1000000)>=4) {
        powerup = false;
        grid.changeLedRGB(powerupx, powerupy, 0, 100, 0);
    }
}


void game::beweeg_doel_y_and_x() {
    int rand();
    if (controle_doel) {
        doel_y = (rand() % 8) + 1;
        doel_x = (rand() % 8) + 1;
    }
}

void game::target_controle() {
    if (player_x == doel_x and player_y == doel_y) {
        controle_doel = true;
    } else {
        controle_doel = false;
    }
}


void game::beweeg_player_y_and_x(int& y,int& x) {
    if (x >= 9000) {
        player_x += 1;

        if (player_x > 8 and powerup) {
            player_x = 1;
        }
        else if (player_x>=8){
            player_x=8;
        }


    }
    else if (x <= -9000) {
        player_x -= 1;
        if (player_x < 1 and powerup) {
            player_x = 8;
            hwlib::cout<<"hallo";
        }
        else if (player_x<=1){
            player_x=1;
        }

    }

    if (y >= 9000) {
        player_y -= 1;
        if (player_y < 1 and powerup) {
            player_y = 8;
        }
        else if (player_y<=1){
            player_y=1;
        }



    }
    else if (y < -9000  ) {
        player_y += 1;
        if (player_y > 8 and powerup) {
            player_y = 1;
        }
        else if (player_y>=8){
            player_y=8;
        }
    }
}

void game::powerup_controle() {
    if (player_x == powerupx and player_y == powerupy) {
        begin_powerup_time = hwlib::now_us();
        controle_powerup = true;
        powerup = true;
    } else {
        controle_powerup = false;
    }
}

void game::beweeg_powerup_x_and_y() {
    int rand();
    if (controle_powerup ) {
        powerupx = (rand() % 8) + 1;
        powerupy = (rand() % 8) + 1;
    }
    if(powerupx==doel_x and powerupy==doel_y){
        doel_x=1;
        powerupy=6;
    }
}



void game::games() {
    hwlib::cout<<chip.temperature()<<hwlib::endl;
    starting();
    time = false;
    while (!gameover) {

        if (punten == 1 and time) {
            begin_time = hwlib::now_us();
        }
        hwlib::wait_ms(300);

        auto x = chip.getaccelx();
        auto y = chip.getaccely();

        clear_grid();
        beweeg_player_y_and_x(y, x);
        powerup_controle();
        target_controle();
        beweeg_doel_y_and_x();
        beweeg_powerup_x_and_y();
        draw_grid();

        if (controle_doel == true) {
            punten++;
            if (punten == 1 and time == false) {
                time = true;
            }
        }

        if (punten == 10) {
             eind_time = hwlib::now_us();
            diff_time = (eind_time - begin_time) / 1000000;
            hwlib::cout <<"10 punten in " <<diff_time << " sec" << hwlib::endl;
            gameover = true;
        }

        grid.write();
    }
}

