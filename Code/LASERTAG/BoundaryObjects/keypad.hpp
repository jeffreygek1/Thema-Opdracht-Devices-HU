/// \file keypad.hpp
/// The keypad file,
/// contains the keypad boundary object declaration
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#include "hwlib.hpp"

/**
 * @author Jeffrey van der Waal
 * @author Maarten Wassenaar
 * @date 08/11/2017
 * 
 * @brief This boundary object waits for the input from the user
 * 
 * This object returns a character, which can be obtained by the keypadController.
 */
class keypad{
private:
    hwlib::keypad<16> keypadIO;
public:
    keypad(hwlib::keypad<16> keypadIO);
	/**
	* @brief Gets an character from the input
	*/
	char get();
};

#endif // KEYPAD_HPP