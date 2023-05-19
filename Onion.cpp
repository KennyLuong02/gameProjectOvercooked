#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Appliance.h"
#include "Player.h"
#include "Onion.h"

#include <SFML/Graphics.hpp>

using namespace std;

Onion::Onion() {
    Appliance();
    onion_amount = 100;
}

int Onion::get_onion_amount() {return onion_amount;}

void Onion::set_onion_amount(int state) {set_state(0);}

void Onion::reset() {
    state = 0;
	m_animation_frame_timer  = 0;
    onion_amount = 100;
}

///////////////////////////////
//Change this to the range of the Onion and Player position
bool Onion::player_collide(const Position& i_player_position) {
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

void Onion::update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, 
                    MAP_WIDTH>& i_map, Player& i_player) {
    
    //Everything in the Onion will work only if the Player is in range
    //Check if the position of the Player is inside the range of the Onion
    //Implement player_collide
    if (player_collide(i_player.get_position()) == true) {

    //Always display this if the Player is inside the range of the Onion
    cout << "Try 'P' to pick up" << endl;

    //If the Player want to pickup Onion
    //Check if the key 'P' is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) == true) {
        //If the Player has empty hand
        if (i_player.get_state() == 0) {
                //Set the Player hand to hold Onion
                i_player.set_state(7);
                onion_amount--;

        } else {
            //Do nothing
            //maybe display this
            cout << "Your hand is not empty" << endl;
        }
    }
    }
}

void Onion::draw(bool i_flash,sf::RenderWindow& i_window) {

}
