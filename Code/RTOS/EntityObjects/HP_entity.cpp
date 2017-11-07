#include "HP_entity.hpp"

HP_entity::HP_entity(int hitpoints):
    hitpoints(hitpoints)
{}

int HP_entity::getHP(){
    return hitpoints;
}

void HP_entity::setHP( int Value ){
    hitpoints = Value;
}



