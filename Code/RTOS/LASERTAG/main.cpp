#include "BeeperTask.hpp"
#include "Beeper.hpp"
#include "RunGameTask.hpp"
#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "Register_entity.hpp"
#include "IR_LED.hpp"
#include "IRSendTask.hpp"
#include "OLED_Controller.hpp"
#include "HP_entity.hpp"
#include "KeyPadTask.hpp"
#include "IRReceiveTask.hpp"
#include "IR_Receiver.hpp"

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
   
    // use the buffered version
    auto oled = hwlib::glcd_oled_buffered( i2c_bus, 0x3c );  

    // this won't work because it doesn't call flush()     
    // hwlib::graphics_random_circles( oled );
   
    auto w1 = hwlib::window_part( 
      oled, 
      hwlib::location( 0, 0 ),
      hwlib::location( 128, 16));
    auto w2 = hwlib::window_part( 
      oled, 
      hwlib::location( 40, 16 ),
      hwlib::location( 88, 32));
//    auto w3 = hwlib::window_part( 
//      oled, 
//      hwlib::location( 0, 32 ),
//      hwlib::location( 128, 48));
    
    auto w4 = hwlib::window_part( 
      oled, 
      hwlib::location( 0, 0 ),
      hwlib::location( 128, 64));
      
    auto f = hwlib::font_default_16x16();
    auto f2 = hwlib::font_default_8x8();
    
    auto d1 = hwlib::window_ostream( w1, f );
    auto d2 = hwlib::window_ostream( w2, f2 );
//    auto d3 = hwlib::window_ostream( w3, f );
    auto d4 = hwlib::window_ostream( w4, f );
   
    Beeper beeper(lsp);
    IR_LED ir_led(ir);
    IR_Receiver receiver(tsop_signal, tsop_gnd, tsop_vdd);
    Register_entity reg(1,1,100);
    HP_entity hp(100);
    auto OLEDController = OLED_Controller(oled, d1, d2, /*d3, */d4);
    
    auto BeeperTask = Beeper_Controller( beeper );
    auto IRSendTask = IR_Send_Controller(ir_led, reg );
    auto RunGameTask = Run_Game_Controller( BeeperTask, IRSendTask, OLEDController, reg, hp);
    auto IRReceiveTask = IR_Receiver_Controller(receiver, RunGameTask);
    auto KeyPadTask = KeyPad_Controller(sw_test, RunGameTask);
   
    hwlib::wait_ms(500);
    (void) BeeperTask;
    (void) IRSendTask;
    (void) RunGameTask;
    (void) IRReceiveTask;
    (void) KeyPadTask;
    rtos::run();

   
}

