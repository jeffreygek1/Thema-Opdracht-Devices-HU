/// \file irLed.hpp
/// The irLed file,
/// contains the irLed boundary object declaration
/// Date file created:
/// \date 06/11/2017
/// Date last modified:
/// \date 08/11/2017

#ifndef IRLED_HPP
#define IRLED_HPP

#include "hwlib.hpp"

/**
 * @author Arsalan Anwari
 * @author Leon Zhang
 * @author Frank Tamer
 * @date 08/11/2017
 * 
 * @brief This boundary object sends the message obtained from the irSendTask
 * 
 * Set an value (1 or 0).
 */
class irLed{
private:
    hwlib::target::d2_36kHz & irLed1;
public: 
    irLed(hwlib::target::d2_36kHz & irLed1);
	/**
	* @brief sets an value, in our case only 1 or 0
	* @param value is the value which contains either 1 or 0.
	*/
	void set(int value);
};

#endif // IRLED_HPP