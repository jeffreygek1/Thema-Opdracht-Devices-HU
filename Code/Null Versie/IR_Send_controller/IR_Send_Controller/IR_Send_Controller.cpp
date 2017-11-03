#include "IR_Send_Controller.hpp"
void IR_Send_Controller::send_signal( int signal )
{
    //for (int i=0; i<16; ++i)
    for (int i=0; i<16; ++i)
    {
        if (signal & 0x8000)
        {
            ir_led.set(1);
            hwlib::wait_us(1600);
            ir_led.set(0);
            hwlib::wait_us(800);
            //hwlib::cout << "1";
        } 
        else
        {
            ir_led.set(1);
            hwlib::wait_us(800);
            ir_led.set(0);
            hwlib::wait_us(1600);
            //hwlib::cout << "0";
        }
        signal = signal << 1;
    }
}
/// \brief This function encodes the signal
//
/// \details This function takes the checksum from the previous function and constructs the signal according
/// to the IR protocol assigned to this assignment. This value is returned for further use. 
int IR_Send_Controller::encode_signal(int & Message, Register_entity & register_entity )
{
    if(register_entity.getPN() != 0){
        Message = register_entity.getFP();
    }
    int checksum = (register_entity.getPN()^Message);
    return ((1<<15)|(register_entity.getPN()<<10)|(Message<<5)|checksum);
}