#ifndef HP_ENTITY_HPP
#define HP_ENTITY_HPP

class HP_entity
{
private:
    int hitpoints;
public:
    HP_entity(int hitpoints);
    int getHP();
    void setHP(int Value);

};

#endif // HP_ENTITY_HPP
