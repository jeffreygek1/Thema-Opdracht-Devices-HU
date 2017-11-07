#ifndef BEEPER_HPP
#define BEEPER_HPP

#include "hwlib.hpp"

class Beeper{
private:
    hwlib::pin_out & lsp;
public:
    Beeper(hwlib::pin_out & lsp);

    void beep( int f, int d, int fd=1000 ); 
    
    void await( long long unsigned int t );


    
};



#endif //BEEPER_HPP 