#include "BeeperTask.hpp"
#include "Beeper.hpp"
#include "RunGameTask.hpp"
#include "bmptk.h"
#include "hwlib.hpp"
#include "rtos.hpp"
#include "Register_entity.hpp"
#include "IR_LED.hpp"
#include "IRSendTask.hpp"

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // wait for the PC terminal to start
   hwlib::wait_ms( 500 );
   
   auto lsp = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto ir = hwlib::target::d2_36kHz();
   
   Beeper beeper(lsp);
   IR_LED ir_led(ir);
   Register_entity reg(1,1,0);
   
   auto BeeperTask = Beeper_Controller( beeper );
   auto SendTask = IR_Send_Controller(ir_led, reg );
   auto RunGameTask = Run_Game_Controller( BeeperTask, SendTask );
   
   hwlib::wait_ms(500);
   (void) BeeperTask;
   (void) SendTask;
   (void) RunGameTask;
   rtos::run();

   
}

