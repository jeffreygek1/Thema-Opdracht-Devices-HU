#include "IRReceiveTask.hpp"

IR_Receiver_Controller::IR_Receiver_Controller( IR_Receiver & receiver, Run_Game_Controller & run_game ):
    task(0, "IRReceiverTask"),
    receiver(receiver),
    run_game(run_game)
{}

int IR_Receiver_Controller::get(){
        corrupt = 0;
        message = 0;
        bool lastMessage = 0;
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
                if(receivedMessages == 1 && (hwlib::now_us()-lastMessageTime)<=4000){
                    lastMessage = 1;
                }
                message = message | 0;
                if( i!=15){
                    message = message << 1;
                }
                else{
                    if(lastMessage){
                        receivedMessages++;
                    }
                    else{
                        receivedMessages = 1;
                    }
                    lastMessageTime = hwlib::now_us();
                }
            }
            
            else if(time>1500 && time<1700){
                if(receivedMessages == 1 && (hwlib::now_us()-lastMessageTime)<=4000){
                    lastMessage = 1;
                }
                message = message | 1;
                if( i!=15){
                    message = message << 1;
                }
                else{
                    if(lastMessage){
                        receivedMessages++;
                    }
                    else{
                        receivedMessages = 1;
                        
                    }
                    lastMessageTime = hwlib::now_us();
                }
            }
            
            else{
                corrupt = 1;
                break;
            }
        }
        return message;
    }
    
int IR_Receiver_Controller::decodePlayerNumber(int message){
        message = message & 31744;
        message = message >> 10;
        return message;
    }
    
int IR_Receiver_Controller::decodeData(int message){
        message = message & 992;
        message = message >> 5;
        return message;
    }
    
int IR_Receiver_Controller::decodeChecksum(int message){
        message = message & 31;
        return message;
    }
    
bool IR_Receiver_Controller::checkChecksum(int playerNumber, int data, int checksum){
        return (checksum == (playerNumber^data));
    }



