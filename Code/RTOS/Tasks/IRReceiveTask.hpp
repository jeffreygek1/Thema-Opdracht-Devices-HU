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
    int corrupt = 0, message = 0, receivedMessages = 0;
    long long int lastMessageTime;
    int playerNumber;
    int data;
    int checksum;

public:
    IR_Receiver_Controller( IR_Receiver & receiver, Run_Game_Controller & run_game );
    
    int get();
    
    int decodePlayerNumber(int message);
    
    int decodeData(int message); 
    
    int decodeChecksum(int message); 
    
    bool checkChecksum(int playerNumber, int data, int checksum);
    
    void main() override{
        for(;;){
            message = get();
            if (!corrupt && receivedMessages == 2){
                
                playerNumber = decodePlayerNumber(message);
                data = decodeData(message);
                checksum = decodeChecksum(message);
                if(checkChecksum(playerNumber, data, checksum)){
                    run_game.setMessageChannelPN(playerNumber);
                    run_game.setMessageChannelData(data);
                    run_game.setReceiveFlag();
                }
                receivedMessages = 0;
            }
        }   
   }
    
};

#endif // IR_RECEIVER_CONTROLLER_HPP