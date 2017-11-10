
/// \file initTask.cpp
/// The initTask file,
/// contains the init control object definition
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

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



