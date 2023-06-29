//
// Created by Thodemar on 23-6-2023.
//

#include "ht1632c.hpp"
#include "hwlib.hpp"


void test_emptyscreen(ht1632c testboard) {
    testboard.empty_screen();

    hwlib::cout << "Branden er nu geen lampjes? (y/n) : \n";
    hwlib::wait_ms(5);

    char result;
    hwlib::cin >> result;

    while (result != 'y' and result != 'n')
        hwlib::cin >> result;

    if (result == 'y') {
        testboard.flush();
        hwlib::cout << "Branden nu dezelfde lampjes als voordat ze uitgingen? (y/n) : \n";
        hwlib::wait_ms(5);

        char result2;
        hwlib::cin >> result2;

        while (result2 != 'y' and result != 'n')
            hwlib::cin >> result;

        if (result2 == 'y') {
            hwlib::cout << "empty_screen() werkt." << hwlib::endl;
            hwlib::wait_ms(5);
        } else if (result == 'n') {
            hwlib::cout << "empty_screen() werkt niet." << hwlib::endl;
            hwlib::wait_ms(5);

        }
    } else if (result == 'n') {
        hwlib::cout << "empty_screen() werkt niet." << hwlib::endl;
        hwlib::wait_ms(5);


        }
    }

void test_xy(ht1632c testboard) {
    for (int i = 0; i < testboard.get_amountMatrixen(); i++) {
        testboard.set_xy(0, 0 + (i * 8),1);
        testboard.set_xy(31, 0 + (i * 8),1);
        testboard.set_xy(0, 7 + (i * 8),1);
        testboard.set_xy(31, 7 + (i * 8),1);
    }
    testboard.flush();

    hwlib::cout << "Branden op alle hoeken lampjes ? (y/n) : \n";
    hwlib::wait_ms(5);

    char result;
    hwlib::cin >> result;

    while (result != 'y' and result != 'n')
        hwlib::cin >> result;

    if (result == 'y') {
        hwlib::cout << "set_xy() werkt." << hwlib::endl;
        hwlib::wait_ms(5);
        test_emptyscreen(testboard);

    } else if (result == 'n') {
        hwlib::cout << "set_xy() werkt niet." << hwlib::endl;
        hwlib::wait_ms(5);


    }
}


void test_getAMountMatrixen(ht1632c testboard) {


    hwlib::cout << "De hoeveelheid aangsloten matrixem is " << testboard.get_amountMatrixen() << " klopt dat? (y/n) : \n";
    hwlib::wait_ms(5);

    char result;
    hwlib::cin >> result;

    while (result != 'y' and result != 'n')
        hwlib::cin >> result;

    if (result == 'y') {
        hwlib::cout << "get_amountMatrixen() werkt." << hwlib::endl;
        hwlib::wait_ms(5);
        test_xy(testboard);
    } else if (result == 'n') {
        hwlib::cout << "get_amountMatrixen() werkt niet." << hwlib::endl;
        hwlib::wait_ms(5);


    }

}



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
        test_getAMountMatrixen(testboard);
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
        hwlib::cout << "de constructor werkt, begin() werkt, fill_matrix() werkt & flush() werkt." << hwlib::endl;
        hwlib::wait_ms(5);
        test_empty(testboard);
    } else if (result == 'n'){
        hwlib::cout << "de constructor werkt, begin(), fill_matrix() of flush() werkt niet." << hwlib::endl;
        hwlib::wait_ms(5);
    }
}




void test_board(ht1632c testboard){
    testboard.begin();
    hwlib::wait_ms(200);
    test_full(testboard);

    hwlib::cout << "Test afgerond";
}