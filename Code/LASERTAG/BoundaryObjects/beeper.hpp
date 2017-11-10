/// \file beeper.hpp
/// The beeper file,
/// contains the beeper boundary object declaration
/// Date file created:
/// \date 06/11/2017
/// Date last modified:
/// \date 08/11/2017

#ifndef BEEPER_HPP
#define BEEPER_HPP

#include "hwlib.hpp"

/**
 * @author Arsalan Anwari
 * @author Leon Zhang
 * @author Frank Tamer
 * @date 08/11/2017
 * 
 * @brief This boundary object creates the sound
 * 
 * This object creates different sounds, depending on how the beep and await are being used.
 */
class beeper{
private:
    hwlib::pin_out & lsp;
public:
    beeper(hwlib::pin_out & lsp);
	/**
	* @brief Beep with a certain frequency at a certain duration, which can be modified
	* @param f is the frequency
	* @param d is the duration
	* @param fd is the modifier
	*/
    void beep(int f, int d, int fd = 1000);
	/**
	* @brief Await for a certain time, to create different kind of sounds 
	* @param t is the time
	*/
    void await(long long unsigned int t);
};

#endif //BEEPER_HPP 