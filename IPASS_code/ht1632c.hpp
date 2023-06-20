//
// Created by Thodemar on 15-6-2023.
//

#include "hwlib.hpp"
#include <vector>


#ifndef IPASS_HT1632C_HPP
#define IPASS_HT1632C_HPP


/// @file

/// \brief
/// ht1632c class
/// \details
/// This is a class that allows you to write information to a ht1632c.
/// The information for each light is stored in a 32x32 array.
/// Because the size of the array it has a max capacity for 4 chips to be send to.
///
/// XY cordinates start at 0,0
///
/// The class allows for the changing of individuel lights or multiple at the same time

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
    /// \brief
    /// Constructor for 1 chip
    /// \details
    /// Constructor initializes the DATA, WR and CS pins and throws them high.
    /// Also sets the amountMatrixen on 1 and fills the matrix with zero's.
    ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1);

    /// \brief
    /// Constructor for 2 chips
    /// \details
    /// Constructor initializes the DATA, WR and CS pins and throws them high.
    /// Also sets the amountMatrixen on 2 and fills the matrix with zero's.
    ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1, hwlib::pin_out & CS2);

    /// \brief
    /// Constructor for 3 chips
    /// \details
    /// Constructor initializes the DATA, WR and CS pins and throws them high.
    /// Also sets the amountMatrixen on 3 and fills the matrix with zero's.
    ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1, hwlib::pin_out & CS2,
            hwlib::pin_out & CS3);

    /// \brief
    /// Constructor for 4 chips
    /// \details
    /// Constructor initializes the DATA, WR and CS pins and throws them high.
    /// Also sets the amountMatrixen on 4 and fills the matrix with zero's.
    ht1632c(hwlib::pin_out & DATAi, hwlib::pin_out & WRi, hwlib::pin_out & CS1, hwlib::pin_out & CS2,
            hwlib::pin_out & CS3, hwlib::pin_out & CS4);

    /// \brief
    /// flushes the matrix onto the screens
    /// \details
    /// completely reflushes the screens with new information from the matrix array.
    void flush();

    void set_xy(int x, int y, bool state);

};


#endif //IPASS_HT1632C_HPP
