#include "HP_entity.hpp"

HP_entity::HP_entity(int hitpoints):
    Hitpoints(hitpoints)
{}

int HP_entity::getHP(){
    return Hitpoints;
}

void HP_entity::setHP( int value ){
    Hitpoints = value;
}



