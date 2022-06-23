#include "hwlib.hpp"
#include "game.hpp"

int main() {
    hwlib::target::pin_oc scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    hwlib::target::pin_oc sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    hwlib::i2c_bus_bit_banged_scl_sda bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
    mpu6050 chip = mpu6050(bus);
    game spel(chip);
    for (;;) {
         spel.games();
        }

}
