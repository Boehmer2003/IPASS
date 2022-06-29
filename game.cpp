// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//
//       Author  :   Benjamin Boehmer
//       Filename:   game.cpp
//       Part of :   IPASS
//
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#include "game.hpp"
#include <cstdlib>


game::game( mpu6050 & chips):
        chip(chips)
        {}

void game::game_reset() {
     test = true;
     game_start = false;
     gameover = false;
     controle_doel = true;
     controle_powerup = true;
     powerup = false;

     diff_time = 0;
     begin_time = 0;
     huidige_tijd = 0;
     begin_powerup_time = 0;
     time_to_beat = 15;
     punten = 0;



}
void game::starting() {
    grid.initialise();
    gameover = false;
    punten = 0;
    test = true;
    while (test) {
        if (chip.test() == 0x68) {
            test = false;
        } else {
            hwlib::cout << "something went wrong with starting the MPU6050" << hwlib::endl;
            test = true;
        }
    }
    grid.changeLedRGB(powerup_x, powerup_y, 0, 100, 0);
}


void game::clear_grid() {
    grid.changeLedRGB(doel_x, doel_y, 0, 0, 0);
    grid.changeLedRGB(player_x, player_y, 0, 0, 0);
    grid.changeLedRGB(powerup_x, powerup_y, 0, 0, 0);

}


void game::draw_grid() {

    grid.changeLedRGB(doel_x, doel_y, 100, 0, 0);
    if (powerup) {
        grid.changeLedRGB(player_x, player_y, 0, 50, 20);
    } else {
        grid.changeLedRGB(player_x, player_y, 0, 0, 100);
    }
    if (((hwlib::now_us() - begin_powerup_time) / 1000000) >= 5) {
        powerup = false;
        grid.changeLedRGB(powerup_x, powerup_y, 0, 100, 0);
    }
}

void game::move_doel_y_and_x() {
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


void game::move_player_y_and_x(int& y,int& x) {
    if (x >= 9000) {
        ++player_x;

        if (player_x > 8 and powerup) {
            player_x = 1;
        } else if (player_x >= 8) {
            player_x = 8;
        }


    } else if (x <= -9000) {
        --player_x;
        if (player_x < 1 and powerup) {
            player_x = 8;
        } else if (player_x <= 1) {
            player_x = 1;
        }

    }

    if (y >= 9000) {
        --player_y;
        if (player_y < 1 and powerup) {
            player_y = 8;
        } else if (player_y <= 1) {
            player_y = 1;
        }


    } else if (y < -9000) {
        ++player_y;
        if (player_y > 8 and powerup) {
            player_y = 1;
        } else if (player_y >= 8) {
            player_y = 8;
        }
    }
}


void game::powerup_controle() {
    if (player_x == powerup_x and player_y == powerup_y) {
        begin_powerup_time = hwlib::now_us();
        controle_powerup = true;
        powerup = true;
    } else {
        controle_powerup = false;
    }
}


void game::move_powerup_x_and_y() {
    if (controle_powerup) {
        powerup_x = (rand() % 8) + 1;
        powerup_y = (rand() % 8) + 1;
    }
    if (powerup_x == doel_x and powerup_y == doel_y) {
        doel_x = 1;
        powerup_y = 6;
    }
}


void game::practice() {
    starting();
    game_start = false;
    while (!gameover) {

        if(game_start){
            huidige_tijd = hwlib::now_us();
        }


        if (punten > 0 and !game_start) {
            begin_time = hwlib::now_us();
            game_start = true;
        }

        hwlib::wait_ms(300);
        auto x = chip.getaccelx();
        auto y = chip.getaccely();

        clear_grid();
        move_player_y_and_x(y, x);
        powerup_controle();
        target_controle();
        move_doel_y_and_x();
        move_powerup_x_and_y();
        draw_grid();

        if (controle_doel) {
            ++punten;
        }
        if (punten == 5) {
            diff_time = (huidige_tijd - begin_time) / 1000000;
            hwlib::cout << "5 punten in  " << diff_time << " sec " << hwlib::endl;
            game_start = false;
            huidige_tijd =0;
            game_start = false;
            gameover = true;
        }


        grid.write();
    }
    game_reset();
}



void game::games() {
    starting();
    while (!gameover) {
        if(game_start){
        huidige_tijd = hwlib::now_us();
        }


        if (punten > 0 and !game_start) {
            begin_time = hwlib::now_us();
            game_start = true;
        }

        hwlib::wait_ms(300);


        auto x = chip.getaccelx();
        auto y = chip.getaccely();

        clear_grid();
        move_player_y_and_x(y, x);
        powerup_controle();
        target_controle();
        move_doel_y_and_x();
        move_powerup_x_and_y();
        draw_grid();

        if (controle_doel) {
            ++punten;
        }
        if (punten == 5 and ((huidige_tijd - begin_time)/1000000)<time_to_beat ) {
            diff_time = (huidige_tijd - begin_time) / 1000000;
            hwlib::cout << "5 punten in met " << time_to_beat-diff_time << " sec over" << hwlib::endl;
            punten = 0;
            begin_time=0;
            huidige_tijd =0;
            game_start = false;
            --time_to_beat;
        }
        else if(((huidige_tijd - begin_time)/1000000)>time_to_beat and !gameover) {
            hwlib::cout<<"helaas je hebt te veloren bij: "<<time_to_beat<<" seconde" <<" en je had "<<punten<<" punt(en)"<<hwlib::endl;
            gameover = true;

        }

        grid.write();
    }

    game_reset();

}
