#include "hwlib.hpp"

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // wait for the PC terminal to start
   hwlib::wait_ms( 500 );
   
   // IR output LED
   auto ir = hwlib::target::d2_36kHz();
   
   // red output LED
   auto red = hwlib::target::pin_out( hwlib::target::pins::d42 );
   
   
   // switch which enables the 36 kHz output
   //auto sw = hwlib::target::pin_in( hwlib::target::pins::d43 );
   
   // when the switch is pressed, 
   // repeat sending 1 ms signal and 1 ms silence
   // and show this on the LED
//   for(;;){
//      hwlib::wait_ms( 1000 ); 
//      ir.set( 1 );
//      red.set( 1 );
//      
//      hwlib::wait_ms( 1000 );
//      ir.set( 0 );
//      red.set( 0 );
//   }
    int reeks = 39321;
    bool out = 0;
    int teller = 0;
    for(teller = 0;teller<16;teller++){
        out = (reeks >> teller) & 1;
        ir.set( out );
        red.set( out );
        hwlib::cout<<out<<hwlib::endl;
        hwlib::wait_ms( 1000 ); 
   }
}

