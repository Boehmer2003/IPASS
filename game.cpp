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
    flag= true;
    punten = 0;
    if (chip.test() == 0x68) {
        hwlib::cout << "Succes " << hwlib::endl;
    } else {
        hwlib::cout << "fail" << hwlib::endl;
    }
    hwlib::wait_ms(2000);

}


void game::clear_grid() {
    grid.changeLedRGB(doel_x, doel_y, 0, 0, 0);
    grid.changeLedRGB(player_x, player_y, 0, 0, 0);



}

void game::draw_grid(){
    grid.changeLedRGB(doel_x, doel_y, 0, 0, 100);
    grid.changeLedRGB(player_x, player_y, 100, 0, 0);



}

int game::beweeg_doel_x(){
    int rand();

    if (controle== true){
        doel_x = (rand()%8)+1;
        return doel_x;
    }
    else {
        return doel_x;
    }


}

int game::beweeg_doel_y(){
    int rand();
    if (controle == true){
        doel_y = (rand()%8)+1;
        return doel_y;
    }
    else {
        return doel_y;
    }

}

bool game::doel_controle(){
        if(player_x==doel_x and player_y == doel_y){
            controle = true;
            return controle;
        }
        else {
            return controle = false;
        }





}

int game::beweeg_player_x(int x) {
    if (x >= 9000) {
        if (player_x == 8) {
            player_x = 0;
        }
        player_x+=1;

    }
    if (x <= -9000) {
        if (player_x == 1) {
            player_x = 9;
        }
        player_x-=1;

    }

    return player_x;


}

int game::beweeg_player_y(int y) {

    if (y >= 9000) {
        if (player_y == 1) {
            player_y = 9;
        }
        player_y-=1;


    }
    if (y <= -9000) {
        if (player_y == 8) {
            player_y = 0;
        }
        player_y+=1;

    }
    return player_y;
}


void game::games() {
    starting();
    tijd = false;
    while(flag) {
        if(punten==1 and tijd){
             begin = hwlib::now_us();

        }
        hwlib::wait_ms(300);
        auto x = chip.getaccelx();
        auto y = chip.getaccely();
        clear_grid();

        player_y=beweeg_player_y(y);
        player_x=beweeg_player_x(x);

        controle = doel_controle();

        doel_y = beweeg_doel_y();
        doel_x = beweeg_doel_x();


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
            flag= false;
        }

        grid.write();
    }
}

