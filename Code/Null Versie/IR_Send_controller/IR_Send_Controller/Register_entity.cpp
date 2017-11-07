#include "Register_entity.hpp"

Register_entity::Register_entity(int Player_number, int Firepower, int Duration)
    : Player_number(Player_number), Firepower(Firepower), Duration(Duration){}

int Register_entity::getFP(){
    return Firepower;
}

int Register_entity::getPN(){
    return Player_number;
}

int Register_entity::getDU(){
    return Duration;
}

void Register_entity::setFP(int Firepower_value){
    Firepower = Firepower_value;
}

void Register_entity::setPN(int Player_number_value){
    Player_number = Player_number_value;
}

void Register_entity::setDU(int Duration_value){
    Duration = Duration_value;
}

