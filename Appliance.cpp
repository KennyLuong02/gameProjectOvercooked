#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"
#include "Appliance.h"

#include <SFML/Graphics.hpp>

using namespace std;

Appliance::Appliance(): m_id(0) {}

Appliance::Appliance(unsigned char i_id): m_id(i_id) {}

int Appliance::get_state() {return state;}

void Appliance::set_state(int state) {
    this-> state = state;
}

void Appliance::reset() {
	state = 0;
	m_animation_frame_timer  = 0;
}

///////////////////////////////
//Do nothing but these need to be here
bool Appliance::player_collide(const Position& i_player_position) { //if the player is in the assign position and press a key then do this
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
void Appliance::draw(bool i_flash, sf::RenderWindow& i_window) {
	unsigned char body_frame = static_cast<unsigned char>(floor(m_animation_frame_timer / static_cast<float>(GHOST_ANIMATION_SPEED)));

	sf::Sprite body;
	sf::Sprite face;

	sf::Texture texture;
	texture.loadFromFile("Resources/Images/Ghost" + std::to_string(CELL_SIZE) + ".png");

	body.setTexture(texture);
	body.setPosition(m_position.x, m_position.y);
	body.setTextureRect(sf::IntRect(CELL_SIZE * body_frame,
	                                0,
									CELL_SIZE,
									CELL_SIZE));

	face.setTexture(texture);
	face.setPosition(m_position.x, m_position.y);

}
