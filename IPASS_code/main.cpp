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

void membit_high(hwlib::target::pin_out & DATA, hwlib::target::pin_out & WR){
//    hwlib::wait_ms(10);
    write_pin(WR,0);
//    hwlib::wait_ms(10);
    write_pin(DATA,1);
//    hwlib::wait_ms(10);
    write_pin(WR,1);
}

void membit_low(hwlib::target::pin_out & DATA, hwlib::target::pin_out & WR){
//    hwlib::wait_ms(10);
    write_pin(WR,0);
//    hwlib::wait_ms(10);
    write_pin(DATA,0);
//    hwlib::wait_ms(10);
    write_pin(WR,1);
}


int main( void ){

    auto CS = hwlib::target::pin_out(hwlib::target::pins::d11);
//    write_pin(CS,0);
//    write_pin(CS,1);
//    write_pin(CS,0);
//    write_pin(CS,1);
    auto DATA = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto WR = hwlib::target::pin_out(hwlib::target::pins::d12);


    auto bord1 = ht1632c(DATA,WR, CS);
    bord1.set_xy(7,1,true);
    bord1.print();




//    auto test = hwlib::target::pin_out(hwlib::target::pins::d7);
//
//    write_pin(test,1);
//
//    write_pin(test,0);

//    write_pin(WR,1);
////    hwlib::wait_ms(10);
//
//    write_pin(DATA,1);
//    hwlib::wait_ms(2);
//
//    write_pin(CS,0);
////    hwlib::wait_ms(10);
//
//
//    membit_high(DATA,WR);
//    membit_low(DATA,WR);
//    membit_high(DATA,WR);
//
//    membit_low(DATA,WR);
//    membit_high(DATA,WR);
//    membit_low(DATA,WR);
//    membit_low(DATA,WR);
//    membit_low(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//
//    membit_low(DATA,WR);
//    membit_low(DATA,WR);
//    membit_low(DATA,WR);
//    membit_low(DATA,WR);
//
//
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//
//    membit_high(DATA,WR);
//    membit_low(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//
//    write_pin(CS,1);

//    hwlib::wait_ms(20);
//
//    write_pin(WR,1);
//
//    write_pin(DATA,1);
//
//    write_pin(CS,0);
//
//    membit_high(DATA,WR);
//    membit_low(DATA,WR);
//    membit_low(DATA,WR);
//
//    membit_low(DATA,WR);
//    membit_low(DATA,WR);
//    membit_low(DATA,WR);
//    membit_low(DATA,WR);
//    membit_low(DATA,WR);
//    membit_low(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//    membit_high(DATA,WR);
//
//    write_pin(CS,1);
//






}

