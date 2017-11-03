#include "RunGameTask.hpp"

Run_Game_Controller::Run_Game_Controller( Beeper_Controller & beeper, IR_Send_Controller & ir_send ):
        task(3, "RunGameTask"),
        beeper(beeper),
        ir_send(ir_send),
        GameStarted(this, "GameStarted")
{}

void Run_Game_Controller::setGameStarted(){
    GameStarted.set();
}