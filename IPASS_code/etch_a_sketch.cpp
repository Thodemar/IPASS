//
// Created by Thodemar on 23-6-2023.
//

#include "hwlib.hpp"
#include "ht1632c.hpp"

void etch_a_sketch(ht1632c & speelbord, hwlib::target::pin_adc & knop1,
                   hwlib::target::pin_adc & knop2, hwlib::pin_in & schakelaar){

    speelbord.begin();
    speelbord.empty_matrix();
    speelbord.flush();
    int amount_matrixen = speelbord.get_amountMatrixen();
    while(true){
        knop1.refresh();
        int y_cord = (knop1.read() / (4095 / (amount_matrixen * 8)));
        knop2.refresh();
        int x_cord = (knop2.read() / (4095 / (32)));
        speelbord.set_xy(x_cord,y_cord,1);
        speelbord.flush();
        hwlib::cout << y_cord << " " << x_cord << "\n";
        hwlib::wait_ms(5);
        schakelaar.refresh();
        bool schakelaarStatus = schakelaar.read();
        if (schakelaarStatus == 0){
            speelbord.empty_matrix();
            speelbord.flush();
            while(schakelaarStatus == 0){
                hwlib::wait_ms(100);
                schakelaar.refresh();
                schakelaarStatus = schakelaar.read();
            }
        }
    }



}