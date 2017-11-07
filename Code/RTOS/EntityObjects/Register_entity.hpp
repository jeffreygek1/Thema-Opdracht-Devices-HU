#ifndef REGISTER_ENTITY_HPP
#define REGISTER_ENTITY_HPP

class Register_entity
{
private:
    int Player_number = 0;
    int Firepower = 0;
    int Duration = 0;
public:
    Register_entity(int Player_number, int Firepower, int Duration);
    int getFP();
    int getPN();
    int getDU();
    void setFP(int Firepower);
    void setPN(int Player_number);
    void setDU(int Duration);
    

};

#endif // REGISTER_ENTITY_HPP