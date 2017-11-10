/// \file irReceiveTask.hpp
/// The irReceiverController file,
/// contains the ir receiver controller object declaration
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#ifndef IR_RECEIVER_CONTROLLER_HPP
#define IR_RECEIVER_CONTROLLER_HPP

#include "irReceiver.hpp"
#include "runGameTask.hpp"
#include "bmptk.h"
#include "rtos.hpp"
#include "hwlib.hpp"

/**
 * @author Maarten Wassenaar
 * @author Jeffrey van der Waal
 * @author Arsalan Anwari
 * @date 08/11/2017
 * 
 * @brief This control object, handles the communication of the ir receiver 
 * 
 * This object is state dependent
 */
class irReceiverController : public rtos::task<>{
private:
    irReceiver & receiver;
    runGameController & runGame;
    int corrupt = 0, message = 0, receivedMessages = 0;
    long long int lastMessageTime;
    int playerNumber;
    int data;
    int checksum;

public:
    irReceiverController( irReceiver & receiver, runGameController & runGame );
    
	/**
	 * @brief This function get the state of the tsopSignal pin. 
	 * @return int 
	 */
    int get();
    
	/**
	 * @brief This function decodes the message to retrieve a player number
	 * @param message: int
	 * @return int
	 */
    int decodePlayerNumber(int message);
    
	/**
	 * @brief This function decodes the message to retrieve some data (ex. Firepower)
	 * @param message: int
	 * @return int
	 */
    int decodeData(int message); 
    
	/**
	 * @brief This function decodes the message to retrieve the checksum of the signal
	 * @param message: int 
	 * @return int 
	 */
    int decodeChecksum(int message); 
    
	/**
	 * @brief This function checks wether a signal is valid by using the OR and Shift operator with the checksum on the message
	 * @param playerNumber : int
	 * @param data: int 
	 * @param checksum: int
	 * @return bool
	 */
    bool checkChecksum(int playerNumber, int data, int checksum);
    
    void main() override{
        for(;;){
            message = get();
            if (!corrupt && receivedMessages == 2){
                
                playerNumber = decodePlayerNumber(message);
                data = decodeData(message);
                checksum = decodeChecksum(message);
                if(checkChecksum(playerNumber, data, checksum)){
                    runGame.setMessageChannelPN(playerNumber);
                    runGame.setMessageChannelData(data);
                    runGame.setReceiveFlag();
                }
                receivedMessages = 0;
            }
        }   
   }
    
};

#endif // IR_RECEIVER_CONTROLLER_HPP