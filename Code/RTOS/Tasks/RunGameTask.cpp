#include "RunGameTask.hpp"

Run_Game_Controller::Run_Game_Controller( Beeper_Controller & beeper, IR_Send_Controller & ir_send, OLED_Controller & oled, Register_entity & reg, HP_entity & hp ):
        task(3, "RunGameTask"),
        beeper(beeper),
        ir_send(ir_send),
        oled(oled),
        reg(reg),
        hp(hp),
//        GameStarted(this, "GameStarted")
        KeyValueChannel(this, "KeyValueChannel"),
        MessageChannelPN(this, "MessageChannelPN"),
        MessageChannelData(this, "MessageChannelData"),
        KeyPressedFlag(this, "KeyPressedFlag"),
        ReceiveFlag(this, "ReceiverFlag")
{}

//void Run_Game_Controller::setGameStarted(){
////    GameStarted.set();
//}

char Run_Game_Controller::getKeyValueChannel(){
    char c = KeyValueChannel.read();
    return c;
}

void Run_Game_Controller::setKeyValueChannel(char key){
    KeyValueChannel.write(key);
}

void Run_Game_Controller::setKeyPressedFlag(){
    KeyPressedFlag.set();
}

int Run_Game_Controller::getMessageChannelPN(){
    int p = MessageChannelPN.read();
    return p;
}

void Run_Game_Controller::setMessageChannelPN(int pn){
    MessageChannelPN.write(pn);
}

int Run_Game_Controller::getMessageChannelData(){
    int p = MessageChannelData.read();
    return p;
}

void Run_Game_Controller::setMessageChannelData(int data){
    MessageChannelData.write(data);
}

void Run_Game_Controller::setReceiveFlag(){
    ReceiveFlag.set();
}
    
int Run_Game_Controller::timePassed(int timeStamp){
    
    int remain_time = (reg.getDU() - (hwlib::now_us() - timeStamp) / 1'000'000);
    return remain_time;
}