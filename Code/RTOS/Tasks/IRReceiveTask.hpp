#ifndef IR_RECEIVER_CONTROLLER_HPP
#define IR_RECEIVER_CONTROLLER_HPP

#include "IR_Receiver.hpp"
#include "RunGameTask.hpp"
#include "bmptk.h"
#include "rtos.hpp"
#include "hwlib.hpp"

class IR_Receiver_Controller : public rtos::task<>{
private:
    IR_Receiver & receiver;
    Run_Game_Controller & run_game;
    int corrupt = 0, message = 0, received_messages = 0;
    long long int last_message_time;

public:
    IR_Receiver_Controller( IR_Receiver & receiver, Run_Game_Controller & run_game );
    
    int get();
    
    int decode_playernumber(int message);
    
    int decode_data(int message); 
    
    int decode_checksum(int message); 
    
    bool check_checksum(int playernumber, int data, int checksum);
    
    void main() override{
        int playernumber;
        int data;
        int checksum;
        for(;;){
            message = get();
            if (!corrupt && received_messages == 2){
                
                playernumber = decode_playernumber(message);
                data = decode_data(message);
                checksum = decode_checksum(message);
                if(check_checksum(playernumber,data,checksum)){
                    run_game.setMessageChannelPN(playernumber);
                    run_game.setMessageChannelData(data);
                    run_game.setReceiveFlag();
                }
                received_messages = 0;
            }
        }   
   }
    
};

#endif // IR_RECEIVER_CONTROLLER_HPP