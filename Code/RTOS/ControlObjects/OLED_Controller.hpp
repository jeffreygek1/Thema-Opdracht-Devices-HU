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
    hwlib::window_ostream & cout4;
public:
    OLED_Controller( 
        hwlib::glcd_oled_buffered & oled, 
        hwlib::window_ostream & cout, 
        hwlib::window_ostream & cout2, 
        hwlib::window_ostream & cout4
    );

    void flush();
    void clear();
    void draw(const hwlib::location & pos);
    
    void printPlayerNumber(int value);
    void printHP_DU( int hp, int du );
    void printGameOver();
    void printPlayerNumberSetup();
    void printFirePowerSetup();
    void printWaitingForCommand();
    void printCommand( int value );
    void printIndicator(char value, char value2 = ' ');

};

#endif // OLEDTASK_HPP
