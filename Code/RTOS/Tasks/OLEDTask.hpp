#ifndef OLEDTASK_HPP
#define OLEDTASK_HPP

#include "bmptk.h"
#include "rtos.hpp"
#include "hwlib.hpp"
#include "Register_entity.hpp"
#include "HP_entity.hpp"

class OLED_Controller : public rtos::task<>
{
private:   
    hwlib::glcd_oled_buffered & oled;
    hwlib::window_ostream & cout;
    hwlib::window_ostream & cout2;
    hwlib::window_ostream & cout3;
    hwlib::window_ostream & cout4;
    Register_entity & reg;
    HP_entity & hp;
    rtos::flag UpdateFlag;
    rtos::pool<int> TimePool;
    rtos::mutex TimeMutex;
public:
    OLED_Controller( 
        hwlib::glcd_oled_buffered & oled, 
        hwlib::window_ostream & cout, 
        hwlib::window_ostream & cout2, 
        hwlib::window_ostream & cout3, 
        hwlib::window_ostream & cout4, 
        Register_entity & reg, 
        HP_entity & hp
    );

    void flush();
    void clear();
    void draw(const hwlib::location & pos);
    
    void printPlayerNumber(int value);
    void printHP( int value );
    void printTime ( int value );
    void updateDisplay();
    void printGameOver();
    
    void setTimePool(int value);
    int getTimePool();
    void setUpdateFlag();
    
    void main() override {
//        auto evt = wait();
        for(;;){
//            if (evt == UpdateFlag){
                wait(UpdateFlag);
//                hwlib::cout << "update oled";
                draw(hwlib::location(10,10));
                //updateDisplay();
//            }else if(evt == GameOverFlag){ printGameOver(); }
            hwlib::wait_ms(1000);
        }
        
    }
    
    
};

#endif // OLEDTASK_HPP
