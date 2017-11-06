#include "InitTask.hpp"

Init_Game_Controller::Init_Game_Controller( IR_Send_Controller & ir_send, OLED_Controller & oled ):
        task(3, "InitTask"),
        ir_send(ir_send),
        oled(oled),
//        GameStarted(this, "GameStarted")
        KeyValueChannel(this, "KeyValueChannel"),
        KeyPressedFlag(this, "KeyPressedFlag")

{}

//void Run_Game_Controller::setGameStarted(){
////    GameStarted.set();
//}

char Init_Game_Controller::getKeyValueChannel(){
    char c = KeyValueChannel.read();
    return c;
}

void Init_Game_Controller::setKeyValueChannel(char key){
    KeyValueChannel.write(key);
}

void Init_Game_Controller::setKeyPressedFlag(){
    KeyPressedFlag.set();
}

int Init_Game_Controller::KeyToInt(char key){
    return (key - '0');
}