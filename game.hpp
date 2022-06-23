//
// Created by benja on 22/06/2022.
//
/// @file


#ifndef V1OOPC_EXAMPLES_GAME_HPP
#define V1OOPC_EXAMPLES_GAME_HPP
#include "hwlib.hpp"
#include "mpu6050.hpp"
#include "leds.hpp"

/// \brief
/// This class is for the game itself and it uses the mpu6050 as controlls

class game {
    const hwlib::target::pins leds = hwlib::target::pins::d3;
    mpu6050 chip;
    ledGrid grid = ledGrid(8, 8, leds);
    bool test = true;
    bool tijd = false;
    bool gameover = true;
    bool controle= true;
    int diff_tijd =0;
    int begin_tijd=0;
    int eind_tijd = 0;
    int punten = 0;
    int doel_x = 1;
    int doel_y = 1;
    int player_x = 4;
    int player_y = 4;

    /// \brief
    /// This function starts the chip and initiliases the led grid.
    /// \details
    /// The function calls multiple other functions from other librarys to start the chips and led grid and it also tests if the mpu6050 is found and working.
    void starting();

    /// \brief
    /// This function removes the old leds that where on
    /// \details
    /// This removes the player and the target so it wil not stay on.
    void clear_grid();

    /// \brief
    /// This draws the new places of the player and the target
    /// \details
    /// This draws the player and the target and if they are not moved they will stay on the same place.
    void draw_grid();
    
    /// \brief
    /// This function looks if the controller has been moved.
    /// \details
    /// The function gets the y and x from the accel x and y and moves the player in the same direction.
    void beweeg_player_y_and_x(int& y,int& x);

    /// \brief
    /// This function moves the target to a new spot
    /// \details
    /// It receives a yes or a no from target_control and if it is a yes it moves the target and else the target will stay on same spot.
    void beweeg_doel_y_and_x();

    /// \brief
    /// This function checks if the target and the player is on the same place.
    /// \details
    /// It looks at the x from the targer and player and also to the y and if they are both the same it sets a  flag to true.
    void target_controle();
public:
    game( mpu6050 chips);

    /// \brief
    /// This function calls upon all the other functions in this class.
    void games();






};


#endif //V1OOPC_EXAMPLES_GAME_HPP
