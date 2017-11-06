#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "IR_LED.hpp"
#include "IRSendTask.hpp"
#include "OLED_Controller.hpp"
#include "KeyPadTask_init.hpp"
#include "InitTask.hpp"
#include "Register_entity.hpp"
#include "Keypad.hpp"

int main( void ){	
    
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
   
    // wait for the PC terminal to start
    hwlib::wait_ms( 500 );
    
    auto sw_test = hwlib::target::pin_in( hwlib::target::pins::d6 ); 
   
    auto lsp = hwlib::target::pin_out( hwlib::target::pins::d7 );
    auto ir = hwlib::target::d2_36kHz();
    
    auto tsop_signal = hwlib::target::pin_in( hwlib::target::pins::d8 );
    auto tsop_gnd    = hwlib::target::pin_out( hwlib::target::pins::d9 );
    auto tsop_vdd    = hwlib::target::pin_out( hwlib::target::pins::d10 );
    
    auto scl = hwlib::target::pin_oc( hwlib::target::pins::scl );
    auto sda = hwlib::target::pin_oc( hwlib::target::pins::sda );
   
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   
    auto oled = hwlib::glcd_oled_buffered( i2c_bus, 0x3c );  

    auto w1 = hwlib::window_part( 
      oled, 
      hwlib::location( 0, 0 ),
      hwlib::location( 128, 16));
      
    auto f = hwlib::font_default_16x16();
    
    auto d1 = hwlib::window_ostream( w1, f );
    auto d2 = hwlib::window_ostream( w1, f );
    auto d4 = hwlib::window_ostream( w1, f );
    
    auto out0 = hwlib::target::pin_oc( hwlib::target::pins::a0 );
    auto out1 = hwlib::target::pin_oc( hwlib::target::pins::a1 );
    auto out2 = hwlib::target::pin_oc( hwlib::target::pins::a2 );
    auto out3 = hwlib::target::pin_oc( hwlib::target::pins::a3 );

    auto in0  = hwlib::target::pin_in( hwlib::target::pins::a4 );
    auto in1  = hwlib::target::pin_in( hwlib::target::pins::a5 );
    auto in2  = hwlib::target::pin_in( hwlib::target::pins::a6 );
    auto in3  = hwlib::target::pin_in( hwlib::target::pins::a7 );
   
    auto out_port = hwlib::port_oc_from_pins( out0, out1, out2, out3 );
    auto in_port  = hwlib::port_in_from_pins( in0, in1,  in2,  in3 );
    auto matrix   = hwlib::matrix_of_switches( out_port, in_port );
    auto keypad_IO   = hwlib::keypad< 16 >( matrix, "DCBA#9630852*741" );
   
    Keypad keypad2(keypad_IO);
    IR_LED ir_led(ir);
    Register_entity reg(0,0,0);

    auto OLEDController = OLED_Controller(oled, d1, d2, d4);
    
    auto IRSendTask = IR_Send_Controller(ir_led, reg );
    auto InitTask = Init_Game_Controller(IRSendTask, OLEDController);
    auto KeyPadTask = keyPadListener2(keypad2, InitTask);
   
    hwlib::wait_ms(500);
    (void) IRSendTask;
    (void) InitTask;
    (void) KeyPadTask;
    rtos::run();

   
}