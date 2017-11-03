#ifndef IR_RECEIVER_CONTROLLER_HPP
#define IR_RECEIVER_CONTROLLER_HPP

#include "ir_receiver.hpp"
#include "rtos.hpp"

class IR_Receiver_Controller : public rtos::task<>{
private:
    ir_receiver &receiver;
    int corrupt = 0, message = 0, received_messages = 0;
    long long int last_message_time;
    
    void main(){
        for(;;){
            message = get();
            if (!corrupt && received_messages == 2){
                int playernumber = decode_playernumber(message);
                int data = decode_data(message);
                int checksum = decode_checksum(message)
                if(checksum)){
                    hwlib::cout<<"PN:"<<decode_playernumber(message)<<"\n";
                    hwlib::cout<<"Data:"<<decode_data(message)<<"\n";
                }
                received_messages = 0;
            }
        }   
   }

public:
    IR_Receiver_Controller( ir_receiver & receiver):
    receiver(receiver)
    {}
    
    int get(){
        corrupt = 0;
        message = 0;
        bool last_message = 0;
        for(int i = 0; i < 16; i++){
            
            auto times = hwlib::now_us();
            while(receiver.get() == 1)
            {
                hwlib::wait_us(50);
                if(hwlib::now_us() - times >= 4000 ){
                    break;
                    corrupt = 1;
                }
            }
            auto start = hwlib::now_us();
            while(receiver.get() == 0)
            {
                hwlib::wait_us(50);
            }
            auto time = hwlib::now_us() - start;
            
            
            if(time>700 && time<900){
                if(received_messages == 1 && (hwlib::now_us()-last_message_time)<=4000){
                    last_message = 1;
                }
                message = message | 0;
                if( i!=15){
                    message = message << 1;
                }
                else{
                    if(last_message){
                        received_messages++;
                    }
                    else{
                        received_messages = 1;
                    }
                    last_message_time = hwlib::now_us();
                }
            }
            
            else if(time>1500 && time<1700){
                if(received_messages == 1 && (hwlib::now_us()-last_message_time)<=4000){
                    last_message = 1;
                }
                message = message | 1;
                if( i!=15){
                    message = message << 1;
                }
                else{
                    if(last_message){
                        received_messages++;
                    }
                    else{
                        received_messages = 1;
                        
                    }
                    last_message_time = hwlib::now_us();
                }
            }
            
            else{
                corrupt = 1;
                break;
            }
        }
        return message;
    }
    
    int decode_playernumber(int message){
        message = message & 31744;
        message = message >> 10;
        return message;
    }
    int decode_data(int message){
        message = message & 992;
        message = message >> 5;
        return message;
    }
    int decode_checksum(int message){
        message = message & 31;
        return message;
    }
    bool checksum(int playernumber, int data, int checksum){
        return (checksum == (playernumber^data));
    }
    
    void print_message(int message){
        hwlib::cout<<"\n"<<message<<"\n";
//        for(int j = 0; j < 16; j++){
//            hwlib::cout<< (message&0x8000 ? 1 : 0);
//            message = message << 1;
//        }
//        hwlib::cout<<"\n";
    }
    
};

#endif // IR_RECEIVER_CONTROLLER_HPP
