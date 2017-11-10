/// \file hpEntity.hpp
/// The hpEntity file,
/// contains the hp entity object declaration
/// Date file created:
/// \date 06-11-2017
/// Date last modified:
/// \date 08-11-2017

#ifndef HP_ENTITY_HPP
#define HP_ENTITY_HPP

/**
 * @author Arsalan Anwari
 * @author Frank Tamer
 * @date 08/11/2017
 * 
 * @brief This HP object contains the health points of the player
 * 
 * This object is used by the run game task 
 */
class hpEntity
{
private:
    int hitpoints;
public:
    hpEntity(int hitpoints);
    
	/**
	 * @brief getter of the player hitpoints
	 * @return hp: int
	 */
	int getHP();
	
	/**
	 * @brief setter of the player hitpoints
	 * @param Value: int
	 */
    void setHP(int Value);

};

#endif // HP_ENTITY_HPP
