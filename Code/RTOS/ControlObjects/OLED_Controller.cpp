#include "OLED_Controller.hpp"

OLED_Controller::OLED_Controller( 
    hwlib::glcd_oled_buffered & oled, 
    hwlib::window_ostream & cout, 
    hwlib::window_ostream & cout2, 
//    hwlib::window_ostream & cout3, 
    hwlib::window_ostream & cout4
):
    oled(oled),
    cout(cout),
    cout2(cout2),
//    cout3(cout3),
    cout4(cout4)
{
    oled.clear();
    oled.flush();
}

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
    cout << "\f" 
        << "=ID:" << value << "==" << "\n";
}

void OLED_Controller::printHP(int hp, int du){
    cout2 << "\f" 
        << "HP:" << hp << "\n"
        << "T :" << du << "s" << "\n" ;
}

void OLED_Controller::printTime(int value){
//    cout3 << "\f" << "T:" << value << "s" << "\n";
}

void OLED_Controller::printGameOver(){
    cout4 
      << "========\n"
      << "GameOver\n"
      << "========\n";  
     flush(); 
}

void OLED_Controller::printCommand(int value){
    cout << "\f" << value << "\n";
}

