//
// Created by Thodemar on 23-6-2023.
//

#include "ht1632c.hpp"
#include "hwlib.hpp"


void test_empty(ht1632c testboard) {
    testboard.empty_matrix();
    testboard.flush();

    hwlib::cout << "Branden er nu geen lampjes meer ? (y/n) : \n";
    hwlib::wait_ms(5);

    char result;
    hwlib::cin >> result;

    while (result != 'y' and result != 'n')
        hwlib::cin >> result;

    if (result == 'y') {
        hwlib::cout << "empty_matrix() werkt." << hwlib::endl;
        hwlib::wait_ms(5);
    } else if (result == 'n') {
        hwlib::cout << "empty_matrix() werkt niet." << hwlib::endl;
        hwlib::wait_ms(5);


    }

}




void test_full(ht1632c testboard){
    testboard.fill_matrix();
    testboard.flush();

    hwlib::cout << "Branden alle lampjes op alle boards? (y/n) : \n";
    hwlib::wait_ms(5);

    char result;
    hwlib::cin >> result;

    while(result != 'y' and result != 'n')
        hwlib::cin >> result;

    if (result == 'y'){
        hwlib::cout << "begin() werkt, fill_matrix() werkt & flush() werkt." << hwlib::endl;
        hwlib::wait_ms(5);
        test_empty(testboard);
    } else if (result == 'n'){
        hwlib::cout << "begin(), fill_matrix() of flush() werkt niet." << hwlib::endl;
        hwlib::wait_ms(5);
    }
}




void test_board(ht1632c testboard){
    testboard.begin();
    test_full(testboard);
}