// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//
//       Author  :   Benjamin Boehmer
//       Filename:   game.hpp
//       Part of :   IPASS
//
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

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
    bool game_start = false;
    bool gameover = false;
    bool controle_doel = true;
    bool controle_powerup = true;
    bool powerup = false;

    int diff_time = 0;
    int begin_time = 0;
    int huidige_tijd = 0;
    int begin_powerup_time = 0;
    int time_to_beat = 15;
    int punten = 0;

    int powerup_x = 6;
    int powerup_y = 6;
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
    void move_player_y_and_x(int &y, int &x);

    /// \brief
    /// This function moves the target to a new spot
    /// \details
    /// It receives a yes or a no from target_control and if it is a yes it moves the target and else the target will stay on same spot.
    void move_doel_y_and_x();

    /// \brief
    /// This function checks if the target and the player is on the same place.
    /// \details
    /// It looks at the x from the target and player and also to the y and if they are both the same it sets a  flag to true.
    void target_controle();

    // \brief
    /// This function moves the powerup to a new spot
    /// \details
    /// It receives a yes or a no from powerup_control and if it is a yes it moves the powerup and else the powerup will stay on same spot.
    void move_powerup_x_and_y();

    /// \brief
    /// This function checks if the powerup and the player is on the same place.
    /// \details
    /// It looks at the x and y from the powerup  and if they are both the same it sets the powerup flag to true.
    void powerup_controle();

    /// \brief
    /// resets everything.
    void game_reset();
public:
    game(mpu6050 &chips);

    /// \brief
    /// This function let's you practise for the game.
    void practice();
    /// \brief
    /// This function calls upon all the other functions in this class.
    /// \details
    /// the game is that you have to get to 5 point as fast as possible before the timer is over.
    void games();

};


#endif //V1OOPC_EXAMPLES_GAME_HPP
