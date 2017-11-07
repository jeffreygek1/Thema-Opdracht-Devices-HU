#include "HP_entity.hpp"

HP_entity::HP_entity(int Hitpoints):
    Hitpoints(Hitpoints)
{}

int HP_entity::getHP(){
    return Hitpoints;
}

void HP_entity::setHP( int Value ){
    Hitpoints = Value;
}



