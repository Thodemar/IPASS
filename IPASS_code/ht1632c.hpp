//
// Created by Thodemar on 15-6-2023.
//

#include "hwlib.hpp"
#include <vector>


#ifndef IPASS_HT1632C_HPP
#define IPASS_HT1632C_HPP


class ht1632c {
private:
    hwlib::pin_out &DATA;
    hwlib::pin_out &WR;
    hwlib::pin_out &CS1;
    hwlib::pin_out &CS2;
    hwlib::pin_out &CS3;
    hwlib::pin_out &CS4;
    bool matrix[32][32];
    int amountMatrixen;

    void write_pin(hwlib::pin_out & pin , bool state);

    void write_membit(bool state);


public:
    ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1);

    ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1, hwlib::pin_out & CS2);

    ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1, hwlib::pin_out & CS2,
            hwlib::pin_out & CS3);

    ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1, hwlib::pin_out & CS2,
            hwlib::pin_out & CS3, hwlib::pin_out & CS4);


    void print();

    void set_xy(int x, int y, bool state);

};


#endif //IPASS_HT1632C_HPP
