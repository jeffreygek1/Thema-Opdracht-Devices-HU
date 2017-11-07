/// \file Beeper.cpp

#include "Beeper.hpp"

Beeper::Beeper( hwlib::pin_out & lsp ):
    lsp(lsp)
{}

void Beeper::beep( int f, int d, int fd ){
    auto t = hwlib::now_us();    
    auto end = t + d;
    while( end > hwlib::now_us() ){
        auto p = 500'000 / f;
        f = f * fd / 1000;
        lsp.set( 1 );
        await( t += p );
        lsp.set( 0 );
        await( t += p );
   }  
}

void Beeper::await(long long unsigned int t){
    while( t > hwlib::now_us() ){}
}