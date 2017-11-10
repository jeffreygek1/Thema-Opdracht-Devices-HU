/// \file registerEntity.hpp
/// The registerEntity file,
/// contains the regsiter entity object declaration
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#ifndef REGISTER_ENTITY_HPP
#define REGISTER_ENTITY_HPP

/**
 * @author Arsalan Anwari
 * @author Leon Zhang
 * @author Frank Tamer
 * @date 08/11/2017
 * 
 * @brief This Entity object contains the health points of the player
 * 
 * This object is used by the run game task 
 */
class registerEntity
{
private:
    int playerNumber = 0;
    int firepower = 0;
    int duration = 0;
public:
// /////////////////////////////////////////////////////////////
// This array is used to store player numbers of other players
// Who fired a shot.
    int playerReg[100];
    int playerRegSize = 0;
///////////////////////////////////////////////////////////////
    registerEntity(int playerNumber, int firepower, int duration);
    /**
     * @brief This is the getter of the players firepower
     * @return fp: int
     */
	int getFP();
	/**
	 * @brief This is the getter of the player number
	 * @return pn: int
	 */
    int getPN();
	/**
	 * @brief This is the getter of the game duration (passed by game leader)
	 * @return du: int
	 */
    int getDU();
	/**
	 * @brief This is the setter of the player fire power
	 * @param firepowerValue: int
	 */
    void setFP(int firepowerValue);
	/**
	 * @brief This is the setter of the player number
	 * @param playerNumberValue: int
	 */
    void setPN(int playerNumberValue);
	/**
	 * @brief This is the setter of the game duration
	 * @param duration: int
	 */
    void setDU(int duration);
    

};

#endif // REGISTER_ENTITY_HPP