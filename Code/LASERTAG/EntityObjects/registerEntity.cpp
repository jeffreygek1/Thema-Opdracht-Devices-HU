#include "registerEntity.hpp"

registerEntity::registerEntity(int playerNumber, int firepower, int duration)
    : playerNumber(playerNumber), firepower(firepower), duration(duration){}

int registerEntity::getFP(){
    return firepower;
}

int registerEntity::getPN(){
    return playerNumber;
}

int registerEntity::getDU(){
    return duration;
}

void registerEntity::setFP(int firepowerValue){
    firepower = firepowerValue;
}

void registerEntity::setPN(int playerNumberValue){
    playerNumber = playerNumberValue;
}

void registerEntity::setDU(int DurationValue){
    duration = DurationValue;
}

