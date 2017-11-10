/// \file beeper.cpp
/// The beeper file,
/// contains the beeper boundary object implementation
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#include "beeper.hpp"

beeper::beeper(
	hwlib::pin_out & lsp
):
    lsp(lsp)
{}

void beeper::beep(int f, int d, int fd){
    auto t = hwlib::now_us();    
    auto end = t + d;
	
    while(end > hwlib::now_us()){
        auto p = 500'000 / f;
        f = f * fd / 1000;
		
        lsp.set(1);
        await(t += p);
        lsp.set(0);
        await(t += p);
   }  
}

void beeper::await(long long unsigned int t){
    while(t > hwlib::now_us()){}
}