#include "InitTask.hpp"

Init_Game_Controller::Init_Game_Controller( IR_Send_Controller & ir_send, OLED_Controller & oled ):
        task(3, "InitTask"),
        ir_send(ir_send),
        oled(oled),
        keyValueChannel(this, "KeyValueChannel"),
        keyPressedFlag(this, "KeyPressedFlag")
{}


char Init_Game_Controller::getKeyValueChannel(){
    char c = keyValueChannel.read();
    return c;
}

void Init_Game_Controller::setKeyValueChannel(char key){
    keyValueChannel.write(key);
}

void Init_Game_Controller::setKeyPressedFlag(){
    keyPressedFlag.set();
}

int Init_Game_Controller::keyToInt(char key){
    return (key - '0');
}



