#include "RunGameTask.hpp"

Run_Game_Controller::Run_Game_Controller( Beeper_Controller & beeper, IR_Send_Controller & ir_send, OLED_Controller & oled, Register_entity & reg, HP_entity & hp ):
        task(3, "RunGameTask"),
        beeper(beeper),
        ir_send(ir_send),
        oled(oled),
        reg(reg),
        hp(hp),
        KeyValueChannel(this, "KeyValueChannel"),
        MessageChannelPN(this, "MessageChannelPN"),
        MessageChannelData(this, "MessageChannelData"),
        KeyPressedFlag(this, "KeyPressedFlag"),
        ReceiveFlag(this, "ReceiverFlag")
{}



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

bool Run_Game_Controller::arrayIsEmpty(int arg){
    return (arg == 0);
}

int Run_Game_Controller::charArrayToInt(char arr[4], int len){
    int result = 0;
    for(int i=0; i<len; i++){
        result = result * 10 + ( arr[i] - '0' );
    }
    return result;
}

void Run_Game_Controller::clearArray(char arr[4], int len){
    for(int i=0; i<len; i++){
        arr[i] = '0';
    }
}