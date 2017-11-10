/// \file oledController.cpp
/// The oledController file,
/// contains the OLED controller object implementation
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#include "oledController.hpp"

oledController::oledController( 
    hwlib::glcd_oled_buffered & oled, 
    hwlib::window_ostream & cout, 
    hwlib::window_ostream & cout2, 
    hwlib::window_ostream & cout3
):
    oled(oled),
    cout(cout),
    cout2(cout2),
    cout3(cout3)
{
    oled.clear();
    oled.flush();
}

void oledController::flush(){
    oled.flush();
}

void oledController::clear(){
    oled.clear();
}

void oledController::draw(const hwlib::location & pos){
    oled.write(pos);
}

void oledController::printPlayerNumber(int value){
    cout 
		<< "\f" 
		<< "=ID:" << value << "==" << "\n";
}

void oledController::printHPDu(int hp, int du){
    cout2 
		<< "\f" 
		<< "HP:" << hp << "\n"
		<< "T :" << du << "s" << "\n" ;
}

void oledController::printGameOver(){
    cout3 << "\f"
		<< "========\n"
		<< "GameOver\n"
		<< "========\n";  
		flush(); 
}

void oledController::printStartInit(){
    cout3 
		<< "\f" 
		<< "Press\n"
		<< "A to\n"
		<< "Start\n";
}

void oledController::printPlayerNumberSetup(){
    cout 
		<< "\f" 
		<< "PN" << "\n"; 
}

void oledController::printFirePowerSetup(){
    cout 
		<< "\f" 
		<< "FP" << "\n"; 
}

void oledController::printWaitingForCommand(){
    cout3 
		<< "\f" 
		<< "Waiting\n"
		<< "For\n"
		<< "Leader\n";
}

void oledController::printCommand(int value){
    cout 
		<< "\f" << value << "\n";
}

void oledController::printCmd(int value){
    cout 
		<< "\f" << "Cmd:" << value << "\n";
}

void oledController::printSend(int value){
    cout 
		<< "\f" << value <<" Send!"<< "\n";
}

void oledController::printGameleader(){
    cout2 
		<< "\f" << "Gameleader"<< "\n"
		<< " ________ " << "\n";
}
void oledController::printIndicator(char value, char value2){
    cout2 
		<< "\f" 
		<< "Input:" << "\n"
		<< value << value2 << "\n" ;
}
