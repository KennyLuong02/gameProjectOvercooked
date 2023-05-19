#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"
#include "Tomato.h"

#include <SFML/Graphics.hpp>

using namespace std;

Tomato::Tomato() {
    state = 0;
    tomato_amount = 100;
}

int Tomato::get_tomato_amount() {return tomato_amount;};

void Tomato::set_tomato_amount(int state) {set_state(0);};

void Tomato::reset() {
    state = 0;
    tomato_amount = 100;
}

///////////////////////////////
//Change this to the range of the Tomato and Player position
bool Tomato::player_collide(const Position& i_player_position) {
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

void Tomato::update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, 
                    MAP_WIDTH>& i_map, Player& i_player) {
    
    //Everything in the Tomato will work only if the Player is in range
    //Check if the position of the Player is inside the range of the Tomato
    //Implement player_collide
    if (player_collide(i_player.get_position()) == true) {

    //Always display this if the Player is inside the range of the Tomato
    cout << "Try 'P' to pick up" << endl;

    //If the Player want to pickup Tomato
    //Check if the key 'P' is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) == true) {
        //If the Player has empty hand
        if (i_player.get_state() == 0) {
                //Set the Player hand to hold Tomato
                i_player.set_state(11);
                tomato_amount--;

        } else {
            //Do nothing
            //maybe display this
            cout << "Your hand is not empty" << endl;
        }
    }
    }
};

        //learn to use this
        void draw(bool i_flash,sf::RenderWindow& i_window); //fix flash and learn render in sfml
