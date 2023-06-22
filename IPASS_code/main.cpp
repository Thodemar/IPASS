// ==========================================================================
//
// blink a led on PIOB pin 27 == arduino-due on-board LED
//
// This file is in the public domain.
//
// ==========================================================================


#include "hwlib.hpp"
#include "ht1632c.hpp"


void write_pin(hwlib::target::pin_out & pin , bool state){
    pin.write(state);
    pin.flush();

    }

int main( void ){

    auto CS1 = hwlib::target::pin_out(hwlib::target::pins::d30);
    auto CS2 = hwlib::target::pin_out(hwlib::target::pins::d30);
    auto CS3 = hwlib::target::pin_out(hwlib::target::pins::d10);
    auto DATA = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto WR = hwlib::target::pin_out(hwlib::target::pins::d12);


    auto bord1 = ht1632c(DATA,WR, CS1);
    bord1.begin();
    bord1.fill_matrix();
    bord1.flush();
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 32; i++) {
            bord1.set_xy(i, j, true);
            bord1.flush();
            hwlib::wait_ms(50);
            bord1.empty_matrix();
        }
    }
//    bord1.set_xy(7,2,true);
    bord1.flush();







}

