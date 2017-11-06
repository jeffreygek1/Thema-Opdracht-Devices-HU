#ifndef OLEDTASK_HPP
#define OLEDTASK_HPP

#include "bmptk.h"
#include "rtos.hpp"
#include "hwlib.hpp"

class OLED_Controller 
{
private:   
    hwlib::glcd_oled_buffered & oled;
    hwlib::window_ostream & cout;
    hwlib::window_ostream & cout2;
//    hwlib::window_ostream & cout3;
    hwlib::window_ostream & cout4;
public:
    OLED_Controller( 
        hwlib::glcd_oled_buffered & oled, 
        hwlib::window_ostream & cout, 
        hwlib::window_ostream & cout2, 
//        hwlib::window_ostream & cout3, 
        hwlib::window_ostream & cout4
    );

    void flush();
    void clear();
    void draw(const hwlib::location & pos);
    
    void printPlayerNumber(int value);
    void printHP( int hp, int du );
    void printTime ( int value );
    void updateDisplay();
    void printGameOver();

};

#endif // OLEDTASK_HPP
