#include "hwlib.hpp"

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // wait for the PC terminal to start
   hwlib::wait_ms( 500 );
   
   // IR output LED
   auto ir = hwlib::target::d2_36kHz();
   
   // red output LED
   auto red = hwlib::target::pin_out( hwlib::target::pins::d3 );
   
    int reeks = 39321;
    bool out = 0;
    int teller, Times_Send;
    for(Times_Send = 0; Times_Send < 2; Times_Send++){
        for(teller = 0;teller<16;teller++){
            out = (reeks >> teller) & 1;
            if( out == 1){
                ir.set( 1 );
                red.set( 1 );
                hwlib::wait_us(800);
                ir.set( 0 );
                red.set( 0 );
                hwlib::wait_us(1600);
            }
            else{
                ir.set( 1 );
                red.set( 1 );
                hwlib::wait_us(1600);
                ir.set( 0 );
                red.set( 0 );
                hwlib::wait_us(800);
            }
        }
        hwlib::wait_ms(3);
    }
}


