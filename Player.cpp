#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Bin.h"
#include "Player.h"

#include <SFML/Graphics.hpp>

// Need some more work


Player::Player(std::string nameInput):
    name(nameInput),
    state(0),
    m_animation_frame_timer(0),

    //don't need?
    m_direction(0),
    m_animation_over(0),
    m_dead(0) {};
    
Player::Player(): 
    name("No Name"),
    state(0),
    m_animation_frame_timer(0),
    
    //don't need?
    m_direction(0),
    m_animation_over(0),
    m_dead(0) {};


void Player::reset() {
    state = 0;
    m_position = {0, 0}; //may change later
    m_animation_frame_timer = 0;
	m_direction = 0;

    //don't need?
    m_direction = 0;
    m_animation_over = 0;
    m_dead = 0;

}

void Player::set_state(int stateInput) {
    state = stateInput;
};
int Player::get_state() {
    return state;
};

void Player::set_player_name(std::string nameInput) {
    name = nameInput;
};
std::string Player::get_player_name() {
    return name;
};

void Player::set_animation_frame_timer(unsigned short i_animation_frame_timer) {
	m_animation_frame_timer = i_animation_frame_timer;
}
unsigned short Player::get_animation_frame_timer() {return m_animation_frame_timer;}


//If you collide then return true or else return false
bool Player::will_i_collide(bool i_collect_pellets, bool i_use_door, /*may not need*/
                            short i_x, short i_y, std::array<std::array<ObjectType, 
                                MAP_HEIGHT>, MAP_WIDTH>& i_map) {
	bool output = false;

	//Getting the exact position
	float cell_x = i_x / static_cast<float>(CELL_SIZE); //what is static_cast
	float cell_y = i_y / static_cast<float>(CELL_SIZE);

	//The Player can intersect 4 cells at most
    //This part is to get the x and y coordinates to use for finding the location
    //on the map later by i_map
	for (unsigned char a = 0; a < 4; a++) {
		short x = 0;
		short y = 0;

		switch (a) {
			case 0: { //Top left cell
				x = static_cast<short>(floor(cell_x));
				y = static_cast<short>(floor(cell_y));
				break;
			} case 1: { //Top right cell
				x = static_cast<short>(ceil(cell_x));
				y = static_cast<short>(floor(cell_y));
				break;
			} case 2: { //Bottom left cell
				x = static_cast<short>(floor(cell_x));
				y = static_cast<short>(ceil(cell_y));
				break;
			} case 3: { //Bottom right cell
				x = static_cast<short>(ceil(cell_x));
				y = static_cast<short>(ceil(cell_y));
			}
		}

		//Making sure that the position is inside the map
		if (x >= 0 && y >= 0 && y < MAP_HEIGHT &&  x > MAP_WIDTH) {
			//Check if there is anything around the Player
            //If there is then return true
            if (i_map[x][y] == ObjectType::STOVE) {
				output = true;

			} else if (i_map[x][y] == ObjectType::DISHWASHER) {   
                output = true;

			} else if (i_map[x][y] == ObjectType::WALL) {   
                output = true;

			} else if (i_map[x][y] == ObjectType::BENCH) {   
                output = true;

			} else if (i_map[x][y] == ObjectType::CUSTOMER) {   
                output = true;

			} else if (i_map[x][y] == ObjectType::BIN) {   
                output = true;
			}
		}
	}

	return output;
}





void Player::update(unsigned char i_level, std::array<std::array<ObjectType,
                         MAP_HEIGHT>, MAP_WIDTH>& i_map) {

    //If the Player want to move in any direction
    //make an array of 4 possible direction
    std::array<bool, 4> possible_collision{};

    //use will_i_collide function to return true if there is a block
    //possible_collision has true if the Player will collide
	possible_collision[0] = will_i_collide(0, 0, m_position.x + PLAYER_SPEED, m_position.y, i_map);   // Right
	possible_collision[1] = will_i_collide(0, 0, m_position.x, m_position.y - PLAYER_SPEED, i_map);   // Up
	possible_collision[2] = will_i_collide(0, 0, m_position.x - PLAYER_SPEED, m_position.y, i_map);   // Left
	possible_collision[3] = will_i_collide(0, 0, m_position.x, m_position.y + PLAYER_SPEED, i_map);   // Down

    //You can turn in this direction if there is nothing
    //Check if the key is pressed
//------------//Need to fix this so the Player only move as long as the key is press
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true) {

        //If the 
		if (possible_collision[0] == false) {
			m_direction = 0; // Right
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true) {
		if (possible_collision[1] == false) {
			m_direction = 1; // Up
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true) {
		if (possible_collision[2] == false) {
			m_direction = 2; // Left
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true) {
		if (possible_collision[3] == false) {
			m_direction = 3; // Down
		}
	}

    //If there is nothing then the Player can move in that direction
//-------//Need to fix this so the Player only move as long as the key is press
	if (possible_collision[m_direction] == false) {
        //If there is no collision happen
		switch (m_direction) {
			case 0: {
				m_position.x += PLAYER_SPEED;   // Right
				break;
			} case 1: {
				m_position.y -= PLAYER_SPEED;  // Up
				break;
			} case 2: {
				m_position.x -= PLAYER_SPEED; // Left
				break;
			} case 3: {
				m_position.y += PLAYER_SPEED;  // Down
			}
		}
	} //else do nothing


    //This is if the Player leave the map
    //Hardcode to make it impossible
	// if (-CELL_SIZE >= m_position.x)
	// {
	// 	m_position.x = CELL_SIZE * MAP_WIDTH - PLAYER_SPEED;
	// }
	// else if (CELL_SIZE * MAP_WIDTH <= m_position.x)
	// {
	// 	m_position.x = PLAYER_SPEED - CELL_SIZE;
	// }

	// if (true == map_collision(1,
	//                           0, 
	// 						  m_position.x, 
	// 						  m_position.y, 
	// 						  i_map)) //When Pacman eats an energizer...
	// {
	// 	//He becomes energized!
	// 	m_energizer_timer = static_cast<unsigned short>(ENERGIZER_DURATION / pow(2, i_level));
	// }
	// else
	// {
	// 	m_energizer_timer = std::max(0, m_energizer_timer - 1);
	// }
};



//learn to use this
void draw(bool i_victory, sf::RenderWindow& i_window);

//don't know
void Player::set_direction(unsigned char i_direction) {
    m_direction = i_direction;
}
unsigned char Player::get_direction() {return m_direction;};
void set_dead(bool i_dead);
bool get_animation_over();
void set_am_I_dead(bool i_am_I_dead);
bool get_am_I_dead();
