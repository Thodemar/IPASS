// ==========================================================================
//
// blink a led on PIOB pin 27 == arduino-due on-board LED
//
// This file is in the public domain.
//
// ==========================================================================


#include "hwlib.hpp"
#include "ht1632c.hpp"
#include "etch_a_sketch.cpp"


int main( void ){

    auto CS1 = hwlib::target::pin_out(hwlib::target::pins::d30);
    auto CS2 = hwlib::target::pin_out(hwlib::target::pins::d26);
    auto CS3 = hwlib::target::pin_out(hwlib::target::pins::d11);
    auto CS4 = hwlib::target::pin_out(hwlib::target::pins::d10);
    auto DATA = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto WR = hwlib::target::pin_out(hwlib::target::pins::d12);


    auto bord1 = ht1632c(DATA,WR, CS1,CS2);
    bord1.begin();
    bord1.empty_matrix();
    bord1.flush();


    auto anolog_pin1 = hwlib::target::pin_adc(hwlib::target::ad_pins::a0);
    auto anolog_pin2 = hwlib::target::pin_adc(hwlib::target::ad_pins::a1);

    auto schakelaar = hwlib::target::pin_in(hwlib::target::pins::d8);
    schakelaar.pullup_disable();


    etch_a_sketch(bord1,anolog_pin1,anolog_pin2, schakelaar);








}

