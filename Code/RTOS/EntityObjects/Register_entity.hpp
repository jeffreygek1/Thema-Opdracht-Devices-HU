#ifndef REGISTER_ENTITY_HPP
#define REGISTER_ENTITY_HPP

class Register_entity
{
private:
    int playerNumber = 0;
    int firepower = 0;
    int duration = 0;
public:
    Register_entity(int playerNumber, int firepower, int duration);
    int getFP();
    int getPN();
    int getDU();
    void setFP(int firepowerValue);
    void setPN(int playerNumberValue);
    void setDU(int duration);
    

};

#endif // REGISTER_ENTITY_HPP