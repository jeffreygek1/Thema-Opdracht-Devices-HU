#include "hwlib.hpp"

void test_dump( hwlib::istream & kbd ){
   int n = 0;
   for(;;){
      auto c = kbd.getc();       
      hwlib::cout << ++n << " [" << c << "]\n";
   }
}

void test_toggle( hwlib::istream & kbd, hwlib::pin_out & led ){
   bool x = 0;
   for(;;){
      (void)kbd.getc();
      x = ! x;
      led.set( x );
   }   
}

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 500 );
   hwlib::cout << "Keypad demo\n";

   auto led = target::pin_out( target::pins::led );
   (void)led;

   auto out0 = target::pin_oc( target::pins::a0 );
   auto out1 = target::pin_oc( target::pins::a1 );
   auto out2 = target::pin_oc( target::pins::a2 );
   auto out3 = target::pin_oc( target::pins::a3 );

   auto in0  = target::pin_in( target::pins::a4 );
   auto in1  = target::pin_in( target::pins::a5 );
   auto in2  = target::pin_in( target::pins::a6 );
   auto in3  = target::pin_in( target::pins::a7 );
   
   auto out_port = hwlib::port_oc_from_pins( out0, out1, out2, out3 );
   auto in_port  = hwlib::port_in_from_pins( in0,  in1,  in2,  in3  );
   auto matrix   = hwlib::matrix_of_switches( out_port, in_port );
   auto keypad   = hwlib::keypad< 16 >( matrix, "123A456B789C*0#D" );
   
   // test_toggle( keypad, led );
   test_dump( keypad );
}
