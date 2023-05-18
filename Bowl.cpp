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


// Need some more work


Bowl::Bowl() {
    Appliance(0);
    content = 0; //No soup inside
    //may need to set the inherited timer to 0
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

//fix this and this can be made into virtual function
void Bowl::update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, 
                    MAP_WIDTH>& i_map, Bowl& i_bowl_1, Player& i_player) {

	//Can the ghost move?
	// bool move = 0;

	//If this is greater than 1, that means that the ghost has reached the intersection.
	//We don't consider the way back as an available way.
	unsigned char available_ways = 0;

	// unsigned char speed          = GHOST_SPEED;

	// std::array<bool, 4> walls{};

	//I used the modulo operator in case the ghost goes outside the grid.
	// if ((m_frightened_mode                 == 2) &&
	//     (m_position.x % GHOST_ESCAPE_SPEED == 0) &&
	// 	(m_position.y % GHOST_ESCAPE_SPEED == 0))
	// {
	// 	speed = GHOST_ESCAPE_SPEED;
	// }

	// update_target(i_pacman.get_direction(),
	//               i_ghost_0.get_position(),
	// 			  i_pacman.get_position());

	//This is so clean! I could spend hours staring at it.
	// walls[0] = map_collision(0, m_use_door, m_position.x + speed, m_position.y,         i_map);
	// walls[1] = map_collision(0, m_use_door, m_position.x,         m_position.y - speed, i_map);
	// walls[2] = map_collision(0, m_use_door, m_position.x - speed, m_position.y,         i_map);
	// walls[3] = map_collision(0, m_use_door, m_position.x,         m_position.y + speed, i_map);

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

    // if (i_player.get_state() != 0) {

    // }



	

	//If the ghost can move, we move it.
	// if (move == 1)
	// {
	// 	switch (m_direction)
	// 	{
	// 		case 0:
	// 		{
	// 			m_position.x += speed;

	// 			break;
	// 		}
	// 		case 1:
	// 		{
	// 			m_position.y -= speed;

	// 			break;
	// 		}
	// 		case 2:
	// 		{
	// 			m_position.x -= speed;

	// 			break;
	// 		}
	// 		case 3:
	// 		{
	// 			m_position.y += speed;
	// 		}
	// 	}

	// 	//Warping.
	// 	//When the ghost leaves the map, we move it to the other side.
	// 	if (m_position.x <= -CELL_SIZE)
	// 	{
	// 		m_position.x = CELL_SIZE * MAP_WIDTH - speed;
	// 	}
	// 	else if (m_position.x >= CELL_SIZE * MAP_WIDTH)
	// 	{
	// 		m_position.x = speed - CELL_SIZE;
	// 	}
	// }

	// if (pacman_collision(i_pacman.get_position()) == true)
	// {
	// 	//When the ghost is not frightened and collides with Pacman, we kill Pacman.
	// 	if (m_frightened_mode == 0) 
	// 	{
	// 		i_pacman.set_am_I_dead(true);
	// 	}
	// 	else //Otherwise, the ghost starts running towards the house.
	// 	{
	// 		m_use_door = true;

	// 		m_frightened_mode = 2;

	// 		m_target_pos = m_home_pos;
	// 	}
	// }
};

        //learn to use this
        void draw(bool i_flash,sf::RenderWindow& i_window); //fix flash and learn render in sfml
