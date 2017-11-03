#include "RunGameTask.hpp"

Run_Game_Controller::Run_Game_Controller( Beeper_Controller & beeper, IR_Send_Controller & ir_send, OLED_Controller & oled, Register_entity & reg ):
        task(3, "RunGameTask"),
        beeper(beeper),
        ir_send(ir_send),
        oled(oled),
        reg(reg)
//        GameStarted(this, "GameStarted")
{}

void Run_Game_Controller::setGameStarted(){
//    GameStarted.set();
}

int Run_Game_Controller::timePassed(int timeStamp){
    
    int remain_time = (reg.getDU() - (hwlib::now_us() - timeStamp) / 1'000'000);
    return remain_time;
}