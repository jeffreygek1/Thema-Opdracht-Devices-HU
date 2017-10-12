#include "hwlib.hpp"
void ir_on_36khz(int time, auto ir){
    ir.set(1);
    hwlib::wait_us(time);
} 
void ir_off_36khz(int time, auto ir){
    ir.set(0);
    hwlib::wait_us(time);
}

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // wait for the PC terminal to start
   hwlib::wait_ms( 500 );
   
   // IR output LED
   auto ir = hwlib::target::d2_36kHz();
   ir.set(0);
   
   
    int reeks = 39321;
    bool out = 0;
    int teller, Times_Send;
        for(Times_Send = 0; Times_Send < 1 ;Times_Send++){
            for(teller = 0;teller<16;teller++){
                out = (reeks >> teller) & 1;
                if( out == 0){
                    //hwlib::cout << "0";
                    ir_on_36khz(800, ir);
                    ir_off_36khz(1600, ir);
                }
                else{
                    //hwlib::cout << "1";
                    ir_on_36khz(1600, ir);
                    ir_off_36khz(800, ir);
                }
            }
            hwlib::wait_ms(1000);
        }
}



