//
// Created by Thodemar on 15-6-2023.
//

#include "ht1632c.hpp"
#include "hwlib.hpp"



void ht1632c::write_pin(hwlib::pin_out & pin , bool state){
    pin.write(state);
    pin.flush();
}

void ht1632c::write_membit(bool state){
    write_pin(WR,0);
    write_pin(DATA, state);
    write_pin(WR,1);
}

ht1632c::ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1)
    :
    DATA(DATAi), WR(WRi),
    CS1(CS1), CS2(hwlib::pin_out_dummy), CS3(hwlib::pin_out_dummy), CS4(hwlib::pin_out_dummy),
    matrix{},
    amountMatrixen(1)
{
    write_pin(CS1,1);
    write_pin(WR,1);
    write_pin(DATA,1);
}


ht1632c::ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1, hwlib::pin_out & CS2)
        :
        DATA(DATAi), WR(WRi),
        CS1(CS1), CS2(CS2), CS3(hwlib::pin_out_dummy), CS4(hwlib::pin_out_dummy),
        matrix{},
        amountMatrixen(2)
{
    write_pin(CS1,1);
    write_pin(CS2,1);

    write_pin(WR,1);
    write_pin(DATA,1);
}

ht1632c::ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1, hwlib::pin_out & CS2,
                 hwlib::pin_out & CS3)
        :
        DATA(DATAi), WR(WRi),
        CS1(CS1), CS2(CS2), CS3(CS3), CS4(hwlib::pin_out_dummy),
        matrix{},
        amountMatrixen(3)
{
    write_pin(CS1,1);
    write_pin(CS2,1);
    write_pin(CS3,1);

    write_pin(WR,1);
    write_pin(DATA,1);
}

ht1632c::ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1, hwlib::pin_out & CS2,
                 hwlib::pin_out & CS3, hwlib::pin_out & CS4)
        :
        DATA(DATAi), WR(WRi),
        CS1(CS1), CS2(CS2), CS3(CS3), CS4(CS4),
        matrix{},
        amountMatrixen(4)
{
    write_pin(CS1,1);
    write_pin(CS2,1);
    write_pin(CS3,1);
    write_pin(CS4,1);

    write_pin(WR,1);
    write_pin(DATA,1);
}


void ht1632c::print() {
    write_pin(CS1,0);

//    matrix[0][7] = 1;

    write_membit(1);
    write_membit(0);
    write_membit(1);

    write_membit(0);
    write_membit(0);
    write_membit(0);
    write_membit(0);
    write_membit(0);
    write_membit(0);
    write_membit(0);

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 8; j++) {
            write_membit(matrix[j][i]);
        }
    }
//    write_membit(1);
//    write_membit(1);
//    write_membit(1);
//    write_membit(1);
//
//    write_membit(1);
//    write_membit(0);
//    write_membit(0);
//    write_membit(1);
//
//    write_membit(1);
//    write_membit(0);
//    write_membit(0);
//    write_membit(1);

}

void ht1632c::set_xy(int x, int y, bool state) {
    matrix[y][x] = state;
}