#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"
#include "Bin.h"

#include <SFML/Graphics.hpp>

using namespace std;

Bin::Bin() {
    Appliance();
}

int Bin::get_state() {return get_state();}

void Bin::set_state(int state) {set_state(0);}

void Bin::reset() {
    state = 0;
	m_animation_frame_timer  = 0;
}

///////////////////////////////
//Change this to the range of the Bin and Player position
bool Bin::player_collide(const Position& i_player_position) { //if the player is in the assign position and press a key then do this
	if ((m_position.x > i_player_position.x - CELL_SIZE) && 
	    (m_position.x < i_player_position.x + CELL_SIZE))
	{
		if ((m_position.y > i_player_position.y - CELL_SIZE) &&
		    (m_position.y < i_player_position.y + CELL_SIZE))
		{
			return true;
		}
	}

	return false;
}

void Bin::update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, 
                    MAP_WIDTH>& i_map, Bowl& i_bowl_1, Player& i_player) {
    
    //Everything in the Bin will work only if the Player is in range
    //Check if the position of the Player is inside the range of the Bin
    //Implement player_collide
    if (player_collide(i_player.get_position()) == true) {

    //Always display this if the Player is inside the range of the Bin
    cout << "Try 'D' to drop food to the bin" << endl;

    //If the Player want to drop food in the Bin
    //Check if the key 'D' is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) == true) { //if it is not on
        //If the Player only holding mushroom, onion, or tomato, or empty hand
        if ((i_player.get_state() == 5) || (i_player.get_state() == 7) ||
                (i_player.get_state() == 11) || (i_player.get_state() == 0)) {
                //Set the Player hand to empty
                i_player.set_state(0);

        } else if ((i_player.get_state() == 15) || (i_player.get_state() == 21) ||
                (i_player.get_state() == 33) || (i_player.get_state() == 23) ||
                    (i_player.get_state() == -1)) {
                //If the Player carry a bowl of soup
                i_player.set_state(-1); //set their state to carry dirty bowl
                i_bowl_1.set_state(-1); //set bowl state to dirty bowl
                
        } else if (i_player.get_state() == 1) {
                //If the Player carry a clean bowl
                i_player.set_state(1); //set their state to carry empty bowl
                i_bowl_1.set_state(1); //set bowl state to clean bowl

        } else {
                i_player.set_state(0);
        }
    }
    }
}

void Bin::draw(bool i_flash,sf::RenderWindow& i_window) {

}
