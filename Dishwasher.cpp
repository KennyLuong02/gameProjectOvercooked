#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"
#include "Appliance.h"
#include "Bowl.h"
#include "Dishwasher.h"


#include <SFML/Graphics.hpp>

using namespace std;

Dishwasher::Dishwasher() {
    Appliance(0);
    is_it_on = false; // If the dishwasher is empty
};

int Dishwasher::get_state() {return get_state();};

void Dishwasher::set_state(int state) {set_state(state);};

bool Dishwasher::get_power_state() {return get_state();};
void Dishwasher::set_power_state(bool n) {
    is_it_on = n;
};

void Dishwasher::reset() {
	state = 0;
	m_animation_frame_timer  = 0;
    is_it_on = false;
}

///////////////////////////////
//Change this to the range of the Stove and Player position
bool Dishwasher::player_collide(const Position& i_player_position) { //if the player is in the assign position and press a key then do this
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

void Dishwasher::update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, 
                    MAP_WIDTH>& i_map, Dishwasher& i_dishwasher, Bowl& i_bowl_1, Player& i_player) {
    
    Position thePlayer = i_player.get_position();
    int x_player_position = thePlayer.x;
    int y_player_position = thePlayer.y;

    Position theBowl = i_bowl_1.get_position();
    int x_bowl_position = theBowl.x;
    int y_bowl_position = theBowl.y;

    int x_dishwasher_position = m_position.x;
    int y_dishwasher_position = m_position.y;

    //Everything in the Dishwasher will work only if the Player is in range
    //Check if the position of the Player is inside the range of the Dishwasher
    //Implement player_collide
    if (player_collide(i_player.get_position()) == true) {

    //Always display this if the Player is inside the range of the Dishwasher
    cout << "Try 'W' to wash the bowl" << endl;
    cout << "Try 'P' to pick up bowl" << endl;

    //If the Player want to wash Bowl in the Dishwasher
    //Check if the key 'W' is pressed and Dishwasher if not on
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) == true) && 
            (is_it_on == false)) { //if it is not on
        if (i_player.get_state() == -1) {
                //turn it on
                is_it_on = true;

                //move the Bowl position to the Dishwasher
                i_bowl_1.set_position(x_dishwasher_position,y_dishwasher_position);
                //make the Player hand empty
                i_player.set_state(0);

                //Hold 'W' for 2 seconds

                //make the Bowl to be clean
                i_bowl_1.set_state(0);
                //turn off the Dishwasher
                is_it_on = false;

        } else {
            //Do nothing
            //maybe display warning
            cout << "You do not have a dirty bowl" << endl;
        }
    }

    //If the Player want to pick up Bowl from the Dishwasher
    //Check if the key 'P' is pressed and Dishwasher is not on
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::P) == true) && 
            (is_it_on == false)) { //maybe true
        
        //check if the Player hand is empty
        if (i_player.get_state() == 0) {
                //change the Bowl position to the Player
                i_bowl_1.set_position(x_player_position,y_player_position);
                //change the state of the Player to the Bowl
                i_player.set_state(i_bowl_1.get_state());

        } else {
            //Do nothing
            //maybe display warning
            cout << "Your hand is not empty" << endl;
        }
    }
    }
}

void Dishwasher::draw(bool i_flash,sf::RenderWindow& i_window) {
    
}
