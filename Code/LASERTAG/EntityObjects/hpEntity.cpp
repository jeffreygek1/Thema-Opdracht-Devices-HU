#include "hpEntity.hpp"

hpEntity::hpEntity(int hitpoints):
    hitpoints(hitpoints)
{}

int hpEntity::getHP(){
    return hitpoints;
}

void hpEntity::setHP( int Value ){
    hitpoints = Value;
}



