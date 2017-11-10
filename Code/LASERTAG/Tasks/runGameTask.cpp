/// \file runGameTask.cpp
/// The runGameTask file,
/// contains the run game controller object definition 
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#include "runGameTask.hpp"

runGameController::runGameController(
	beeperController & beeperControl, 
	irSendController & irSend, 
	oledController & oledControl, 
	registerEntity & reg, 
	hpEntity & hp):
        task(3, "RunGameTask"),
        beeperControl(beeperControl),
        irSend(irSend),
        oledControl(oledControl),
        reg(reg),
        hp(hp),
        keyValueChannel(this, "KeyValueChannel"),
        messageChannelPN(this, "MessageChannelPN"),
        messageChannelData(this, "MessageChannelData"),
        keyPressedFlag(this, "KeyPressedFlag"),
        receiveFlag(this, "ReceiverFlag"),
        coolDownTimer(this, "CoolDownTimer")
{}



char runGameController::getKeyValueChannel(){
    char c = keyValueChannel.read();
    return c;
}

void runGameController::setKeyValueChannel(char key){
    keyValueChannel.write(key);
}

void runGameController::setKeyPressedFlag(){
    keyPressedFlag.set();
}

int runGameController::getMessageChannelPN(){
    int p = messageChannelPN.read();
    return p;
}

void runGameController::setMessageChannelPN(int pn){
    messageChannelPN.write(pn);
}

int runGameController::getMessageChannelData(){
    int p = messageChannelData.read();
    return p;
}

void runGameController::setMessageChannelData(int data){
    messageChannelData.write(data);
}

void runGameController::setReceiveFlag(){
    receiveFlag.set();
}
    
int runGameController::timePassed(int timeStamp){
    
    int remainTime = (reg.getDU() - (hwlib::now_us() - timeStamp) / 1'000'000);
    return remainTime;
}

bool runGameController::arrayIsEmpty(int arg){
    return (arg == 0);
}

int runGameController::charArrayToInt(char arr[3], int len){
    int result = 0;
    for(int i=0; i<len; i++){
        result = result * 10 + ( arr[i] - '0' );
    }
    return result;
}

void runGameController::clearArray(char arr[3], int len){
    for(int i=0; i<len; i++){
        arr[i] = '0';
    }
}

void runGameController::countDown(int dur){
    while (dur > 0){
        oledControl.printCommand(dur--);
        oledControl.flush();
    }
}

void runGameController::showPlayersHitBy(){
    hwlib::cout << "Players you got hit by: \n";
    for(int i=0; i<reg.playerRegSize; ++i){
        hwlib::cout << i << " : " << "player" << reg.playerReg[i] << "\n";
    }
}

