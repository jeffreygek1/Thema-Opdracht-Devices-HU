#include "Register_entity.hpp"

Register_entity::Register_entity(int playerNumber, int firepower, int duration)
    : playerNumber(playerNumber), firepower(firepower), duration(duration){}

int Register_entity::getFP(){
    return firepower;
}

int Register_entity::getPN(){
    return playerNumber;
}

int Register_entity::getDU(){
    return duration;
}

void Register_entity::setFP(int firepowerValue){
    firepower = firepowerValue;
}

void Register_entity::setPN(int playerNumberValue){
    playerNumber = playerNumberValue;
}

void Register_entity::setDU(int DurationValue){
    duration = DurationValue;
}

