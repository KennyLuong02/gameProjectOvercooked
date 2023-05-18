#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"
#include "Appliance.h"
#include "Stove.h"

#include <SFML/Graphics.hpp>

using namespace std;

Stove::Stove() {
    Appliance(0);
    content = 0; //No soup inside
    is_it_cooked = false;
    //may need to set the inherited timer to 0
};

int Stove::get_state() {return get_state();};

void Stove::set_state(int state) {set_state(state);};

int Stove::get_content() {return content;};

void Stove::set_content(int contentt) {
    this-> content = content;
    // if (contentt == 0 || contentt == 15 || contentt == 21 || contentt == 33 || contentt == 23) {
    //     this-> content = content; //Either 0: empty, 15: Mushroom soup, 21: Onion soup, 33: Tomato soup, 23: Com soup
    // } else {
    //     cout << "Cannot put this into the bowl" << endl; //need to change it in the SFML version
    // }
};

bool Stove::get_cooking_state() {return is_it_cooked;};
void Stove::set_cooking_state(bool cook_yet) {
    is_it_cooked = cook_yet;
};

void Stove::reset() {
	reset();
    content = 0;
}

///////////////////////////////
//Change this to the range of the Stove and Player position
bool Stove::player_collide(const Position& i_player_position) { //if the player is in the assign position and press a key then do this
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

//fix this and this can be made into virtual function
void Stove::update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, 
                    MAP_WIDTH>& i_map, Stove& i_stove, Bowl& i_bowl_1, Player& i_player, int content_to_add) {
    
    Position thePlayer = i_player.get_position();
    int x_player_position = thePlayer.x;
    int y_player_position = thePlayer.y;

    int x_stove_position = m_position.x;
    int y_stove_position = m_position.y;

    //Everything in the Stove will work only if the Player is in range
    //Check if the position of the Player is inside the range of the Stove
    //Implement player_collide
    if (player_collide(i_player.get_position()) == true) {

    //Always display this if the Player is inside the range of the Stove
    cout << "Try 'D' to drop food into the stove" << endl;
    cout << "Try 'C' to cook food" << endl;
    cout << "Try 'P' to pick up food" << endl;

    //If the Player want to put food in the Stove
    //Check if the Player has something and check if the Stove is not full
    if ((i_player.get_state() != 0) && (get_state() <= 33)) { //33 is the maximum amount allowed
        //To put content inside the stove
        //Check if the 'D' key is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true &&
                get_cooking_state() == false) { //Press 'D' instead of Down 
                
            //Check the state of the player
            //Then add teh appropriate food in the stove and empty Player hand
            if (i_player.get_state() == 5) {
                content += content_to_add;
                set_cooking_state(false);
                i_player.set_state(0);

            } else if (i_player.get_state() == 7) {
                content += content_to_add;
                set_cooking_state(false);
                i_player.set_state(0);

            } else if (i_player.get_state() == 11) {
                content += content_to_add;
                set_cooking_state(false);
                i_player.set_state(0);
                
            } else {
                content += 0;
                //may display a warning
                cout << "Cannot add this item to the stove" << endl;
            }
        }
    }


    //If the Player want to cook food
    if (get_state() <= 33) { //33 is the maximum amount allowed
        //Check if the 'C' key is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true) { //Press 'C' instead of Up
            //Hold 'C' for 3 seconds
            //Then the food cooked, maybe a display
            set_cooking_state(true);
        }
    }
    

    //If the Player want to pick up soup
    //check if they press 'P'
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true) { //Press 'P' instead of Right
        //check if they have an empty bowl
        if ((i_player.get_state() == 53) || (i_player.get_state() == 100) || (i_player.get_state() == 150)) {
            //check if the food is cooked
            if (is_it_cooked == true) {
                i_bowl_1.set_content(content + i_player.get_state());
            } else {
                //Do nothing
                //Maybe display a warning
                cout << "Food is not cooked" << endl; //Change this later
            }
        } else {
            //Do nothing
            //Maybe display a warning
            cout << "You don't have a bowl to contain food" << endl;
        }
    }
    }

};

        //learn to use this
        void draw(bool i_flash,sf::RenderWindow& i_window); //fix flash and learn render in sfml
