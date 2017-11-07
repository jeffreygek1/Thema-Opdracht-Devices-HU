#include "OLED_Controller.hpp"

OLED_Controller::OLED_Controller( 
    hwlib::glcd_oled_buffered & oled, 
    hwlib::window_ostream & cout, 
    hwlib::window_ostream & cout2, 
    hwlib::window_ostream & cout4
):
    oled(oled),
    cout(cout),
    cout2(cout2),
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
    cout 
        << "\f" 
        << "=ID:" << value << "==" << "\n";
}

void OLED_Controller::printHP_DU(int hp, int du){
    cout2 
        << "\f" 
        << "HP:" << hp << "\n"
        << "T :" << du << "s" << "\n" ;
}

void OLED_Controller::printGameOver(){
    cout4 << "\f"
      << "========\n"
      << "GameOver\n"
      << "========\n";  
     flush(); 
}

void OLED_Controller::printstartInit(){
    cout4 << "\f" 
        << "Press\n"
        << "A to\n"
        << "Start\n";
}

void OLED_Controller::printPlayerNumberSetup(){
    cout 
        << "\f" 
        << "PN" << "\n"; 
}

void OLED_Controller::printFirePowerSetup(){
    cout 
        << "\f" 
        << "FP" << "\n"; 
}

void OLED_Controller::printWaitingForCommand(){
    cout4 << "\f" 
        << "Waiting\n"
        << "For\n"
        << "Leader\n";
}

void OLED_Controller::printCommand(int value){
    cout 
        << "\f" << value << "\n";
}

void OLED_Controller::printIndicator(char value, char value2 ){
    cout2 << "\f" 
        << "Input:" << "\n"
        << value << value2 << "\n" ;
}
