#include <iostream>
#include <string>
#include "Position.h"
#include "Player.h"

#include <SFML/Graphics.hpp>

#include "Headers/MapCollision.hpp"

// Need some more work


Player::Player(std::string nameInput): 
    name(nameInput),
    state(0),
    m_direction(0),
    m_animation_frame_timer(0) {};
Player::Player(): 
    Player("No Name"),
    state(0),
    m_direction(0),
    m_animation_frame_timer(0) {};


void Player::reset() {
    state = 0;
    m_position = {0, 0}; //may change later
	m_direction = 0;
	m_animation_frame_timer = 0;

}


void Player::set_animation_frame_timer(unsigned short i_animation_frame_timer) {
	m_animation_frame_timer = i_animation_frame_timer;
}
unsigned short Player::get_animation_frame_timer() {return m_animation_frame_timer;}


void Player::set_direction(unsigned char i_direction) {
    m_direction = i_direction;
}
unsigned char Player::get_direction() {return m_direction;};


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





        void draw(bool i_victory, sf::RenderWindow& i_window); //

	    void update(unsigned char i_level, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map); //

        void bin();

