// ==========================================================================
//
// blink a led on PIOB pin 27 == arduino-due on-board LED
//
// This file is in the public domain.
//
// ==========================================================================


#include "hwlib.hpp"
#include "ht1632c.hpp"


int main( void ){

    auto CS1 = hwlib::target::pin_out(hwlib::target::pins::d30);
    auto CS2 = hwlib::target::pin_out(hwlib::target::pins::d26);
//    auto CS3 = hwlib::target::pin_out(hwlib::target::pins::d10);
//    auto CS4 = hwlib::target::pin_out(hwlib::target::pins::d10);
    auto DATA = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto WR = hwlib::target::pin_out(hwlib::target::pins::d12);


    auto bord1 = ht1632c(DATA,WR, CS1, CS2);
    bord1.begin();
    bord1.empty_matrix();
    bord1.flush();

    int amount_matrixen = bord1.get_amountMatrixen();
    auto anolog_pin1 = hwlib::target::pin_adc(hwlib::target::ad_pins::a0);
    auto anolog_pin2 = hwlib::target::pin_adc(hwlib::target::ad_pins::a1);
    while(true){
        anolog_pin1.refresh();
        int y_cord = (anolog_pin1.read() / (4095 / (amount_matrixen * 8)));
        anolog_pin2.refresh();
        int x_cord = (anolog_pin2.read() / (4095 / (32)));
        bord1.set_xy(x_cord,y_cord,1);
        bord1.flush();
        hwlib::cout << y_cord << " " << x_cord << "\n";
        hwlib::wait_ms(5);

    }







}

