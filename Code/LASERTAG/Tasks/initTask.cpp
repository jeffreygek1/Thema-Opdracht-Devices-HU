#include "initTask.hpp"

initGameController::initGameController( irSendController & irSend, oledController & oledControl ):
        task(3, "InitTask"),
        irSend(irSend),
        oledControl(oledControl),
        keyValueChannel(this, "KeyValueChannel"),
        keyPressedFlag(this, "KeyPressedFlag")
{}


char initGameController::getKeyValueChannel(){
    char c = keyValueChannel.read();
    return c;
}

void initGameController::setKeyValueChannel(char key){
    keyValueChannel.write(key);
}

void initGameController::setKeyPressedFlag(){
    keyPressedFlag.set();
}

int initGameController::keyToInt(char key){
    return (key - '0');
}



