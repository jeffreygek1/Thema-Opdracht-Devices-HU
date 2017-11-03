#include "OLEDTask.hpp"

OLED_Controller::OLED_Controller( 
    hwlib::glcd_oled_buffered & oled, 
    hwlib::window_ostream & cout, 
    hwlib::window_ostream & cout2, 
    hwlib::window_ostream & cout3, 
    hwlib::window_ostream & cout4, 
    Register_entity & reg, 
    HP_entity & hp
):
    task(4, "OLEDTask"), // laagste prioriteit
    oled(oled),
    cout(cout),
    cout2(cout2),
    cout3(cout3),
    cout4(cout4),
    reg(reg),
    hp(hp),
    UpdateFlag(this, "UpdateFlag"),
    TimePool("TimePool"),
    TimeMutex("TimeMutex")
{}

void OLED_Controller::flush(){
    oled.flush();
}

void OLED_Controller::clear(){
    oled.clear();
}

void OLED_Controller::draw(const hwlib::location & pos){
    oled.write(pos);
}

void OLED_Controller::printPlayerNumber(int value){
    cout << "\f" << "ID: " << value << "\n";
}

void OLED_Controller::printHP(int value){
    cout2 << "\f" << "HP: " << value << "\n";
}

void OLED_Controller::printTime(int value){
    cout3 << "\f" << value << "s" << "\n";
}

void OLED_Controller::updateDisplay(){
    printPlayerNumber( reg.getPN() );
    printHP( hp.getHP() );
    // Fix delay --> mabey fixed
    printTime( getTimePool() );
}

void OLED_Controller::printGameOver(){
    cout4 
      << "========\n"
      << "GameOver\n"
      << "========\n";  
}

void OLED_Controller::setTimePool(int value){
    TimeMutex.wait();
    TimePool.write(value);
    TimeMutex.signal();
}

int OLED_Controller::getTimePool(){
    TimeMutex.wait();
    int n = TimePool.read();
    TimeMutex.signal();
    return n;
}

void OLED_Controller::setUpdateFlag(){
    UpdateFlag.set();
}
