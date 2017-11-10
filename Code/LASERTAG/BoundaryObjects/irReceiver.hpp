/// \file irReceiver.hpp
/// The irReceiver file,
/// contains the IR receiver boundary object declaration
/// Date file created:
/// \date 06/11/2017
/// Date last modified:
/// \date 08/11/2017

#ifndef IRRECEIVER_HPP
#define IRRECEIVER_HPP

#include "hwlib.hpp"

/**
<<<<<<< HEAD
 * @author Jeffrey van der Waal
 * @author Maarten Wassenaar
=======
 * @author Arsalan Anwari
>>>>>>> 9cc34721f0204cfc1dc44d6bd1459153c6467968
 * @date 08/11/2017
 * 
 * @brief This boundary object receives messages
 * 
 * Initializes the receiver and checks the pin.
 */
class irReceiver{
private:
    hwlib::target::pin_in & tsopSignal;
    hwlib::target::pin_out & tsopGnd;
    hwlib::target::pin_out & tsopVdd;
public:
    irReceiver(
	hwlib::target::pin_in & tsopSignal, 
	hwlib::target::pin_out & tsopGnd, 
	hwlib::target::pin_out & tsopVdd);

	/**
	* @brief Used for the initialization of the IR receiver
	*/
    void setup();
	/**
	* @brief Checks the state of the pin (high or low)
	*/
    bool get();
};

#endif // IRRECEIVER_HPP
