/// \file oledController.hpp
/// The oledController file,
/// contains the OLED controller object declaration
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#ifndef OLEDTASK_HPP
#define OLEDTASK_HPP

#include "bmptk.h"
#include "rtos.hpp"
#include "hwlib.hpp"

/**
 * @author Arsalan Anwari
 * @author Leon Zhang
 * @author Frank Tamer
 * @date 08/11/2017
 * 
 * @brief This controller object prints pixels on the screen
 * 
 * Depending on which functions are called, it will print the pixels on the screen. 
 * We divided the OLED in 3 segments, so we do not always have to update the whole display, 
 * but rather update that what is necessary.
 */
class oledController{
private:   
    hwlib::glcd_oled_buffered & oled;
    hwlib::window_ostream & cout;
    hwlib::window_ostream & cout2;
    hwlib::window_ostream & cout3;
public:
    oledController( 
        hwlib::glcd_oled_buffered & oled, 
        hwlib::window_ostream & cout, 
        hwlib::window_ostream & cout2, 
        hwlib::window_ostream & cout3
    );
	/**
	* @brief This function updates the display memory of the oled.
	*/
    void flush();
	/**
	* @brief This function clears the display memory so the no pixels will be set on the display 
	*/
    void clear();
	/**
	* @brief This function draws a single pixel on the display
	* @param pos: &hwlib::location, simular to a inverted 2d coordinate
	*/
    void draw(const hwlib::location & pos);
    /**
	* @brief This function prints the player number on the display 
	* @param value: int, the player number
	*/
    void printPlayerNumber(int value);
	/**
	* @brief This function prints the players health and the duration of the game
	* @param hp: int, player health 
	* @param du: int, game duration
	*/
    void printHPDu(int hp, int du);
	/**
	* @brief This function displays a gameover screen. 
	*/
    void printGameOver();
	/**
	* @brief This function will display a message at the start of the initialization process.
	* @details The Message: "Press A to start"
	*/
    void printStartInit();
	/**
	* @brief This function will indicate on the display that a player number has to be inserted by the player 
	*/
    void printPlayerNumberSetup();
	/**
	* @brief This function will indicate on the display that the fire power has to be inserted by the player
	*/
    void printFirePowerSetup();
	/**
	* @brief This function will indicate on the display that a player has to wait for a signal of the game leader
	*/
    void printWaitingForCommand();
	//
	/**
	* @brief This function will print a number on the display (used by player)
	* @param value: int, the number that will be printed
	*/
    void printCommand(int value);
	/**
	* @brief This function will print a commando value on the display (used by gameleader) 
	* @param value: int, commando value that will be printed
	*/
    void printCmd(int value);
	/**
	* @brief This function will display a message if a signal has been send.
	* @param value: int, signal that was send. 
	*/
    void printSend(int value);
	/**
	* @brief This function will display that the device is a game leader 
	*/
    void printGameleader();
	/**
	* @brief This function will display the input of the player 
	* @param value: char, first input
	* @param value2: char, second input 
	*/
    void printIndicator(char value, char value2 = ' ');
};

#endif // OLEDTASK_HPP