#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"
#include "Appliance.h"
#include "MapCollide.h"
#include "Bowl.h"

#include <SFML/Graphics.hpp>

using namespace std;

Bowl::Bowl() {
    Appliance(0);
    content = 0; //No soup inside
};

int Bowl::get_state() {return get_state();};

void Bowl::set_state(int state) {set_state(state);};

int Bowl::get_content() {return content;};

void Bowl::set_content(int contentt) {
    if (contentt == 0 || contentt == 15 || contentt == 21 || contentt == 33 || contentt == 23) {
        this-> content = content; //Either 0: empty, 15: Mushroom soup, 21: Onion soup, 33: Tomato soup, 23: Com soup
    } else {
        cout << "Cannot put this into the bowl" << endl; //need to change it in the SFML version
    }
};

void Bowl::reset() {
	reset();
    content = 0;
}

///////////////////////////////
//Fix this
bool Bowl::player_collide(const Position& i_player_position) { //if the player is in the assign position and press a key then do this
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

//fix this
void Bowl::update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, 
                    MAP_WIDTH>& i_map, Bowl& i_bowl_1, Player& i_player) {
	
    Position thePlayer = i_player.get_position();
    int x_player_position = thePlayer.x;
    int y_player_position = thePlayer.y;

    int x_bowl_position = m_position.x;
    int y_bowl_position = m_position.y;

    //If the Player want to pick up a bowl
    if (i_player.get_state() == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) == true) { //Press 'B' instead of Down
            i_bowl_1.set_position(x_player_position,y_player_position);
            i_player.set_state(i_bowl_1.get_state()); //assuming they are carrying the first bowl and it is empty
                                   //change this later
        }
    } else {
        cout << "Your hand is full" << endl; //change this later
    }

};

        //learn to use this
        void draw(bool i_flash,sf::RenderWindow& i_window); //fix flash and learn render in sfml
