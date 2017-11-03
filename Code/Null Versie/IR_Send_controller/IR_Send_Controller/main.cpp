#include "IR_Send_Controller.hpp"
#include "Register_entity.hpp"

int main(int argc, char **argv)
{
// kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   // wait for the PC terminal to start
   hwlib::wait_ms( 500 );
   
   auto ir_led =  hwlib::target::d2_36kHz();
   
   IR_LED ir_send(ir_led);
   IR_Send_Controller ir_control(ir_send);
   Register_entity register_entity(12,4,0);
   int value = 5524;
   
   hwlib::wait_ms( 500 );
   int signal = ir_control.encode_signal(value, register_entity);
   hwlib::cout << "\n" <<signal << "\n";
   for(int i = 0; i < 2; i++)
    {
            ir_control.send_signal(signal);// delay 3244us tussen sender en receiver
            hwlib::wait_us(1);
    }
//    auto time = hwlib::now_us();
//    hwlib::cout << "0";
//    int timed = hwlib::now_us()- time;
//    hwlib::cout << timed;
   
}
