#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"
#include "Appliance.h"
#include "MapCollide.h"

#include <SFML/Graphics.hpp>

using namespace std;

Appliance::Appliance(): m_id(0) {};

Appliance::Appliance(unsigned char i_id): m_id(i_id) {};

int Appliance::get_state() {return state;};

void Appliance::set_state(int state) {
    this-> state = state; //Either 0: empty, 1:full, or -1: dirty
};

void Appliance::reset() {
	state = 0;
	m_animation_frame_timer  = 0;
}

///////////////////////////////
//Fix this
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

void Appliance::draw(bool              i_flash,
                 sf::RenderWindow& i_window)
{
	//Current frame of the animation.
	unsigned char body_frame = static_cast<unsigned char>(floor(m_animation_frame_timer / static_cast<float>(GHOST_ANIMATION_SPEED)));

	sf::Sprite body;
	sf::Sprite face;

	sf::Texture texture;
	texture.loadFromFile("Resources/Images/Ghost" + std::to_string(CELL_SIZE) + ".png");

	body.setTexture(texture);
	body.setPosition(m_position.x, m_position.y);
	//Animation is basically a quick display of similar images.
	//So that's what we're doing here.
	body.setTextureRect(sf::IntRect(CELL_SIZE * body_frame,
	                                0,
									CELL_SIZE,
									CELL_SIZE));

	face.setTexture(texture);
	face.setPosition(m_position.x, m_position.y);

	//The "I'm not frightened" look.
	if (m_frightened_mode == 0)
	{
		switch (m_id)
		{
			case 0:
			{
				//Red color
				body.setColor(sf::Color(255, 0, 0));

				break;
			}
			case 1:
			{
				//Pink color
				body.setColor(sf::Color(255, 182, 255));

				break;
			}
			case 2:
			{
				//Cyan color (I still don't understand why they called it blue)
				body.setColor(sf::Color(0, 255, 255));

				break;
			}
			case 3:
			{
				//Orange color
				body.setColor(sf::Color(255, 182, 85));
			}
		}

		face.setTextureRect(sf::IntRect(CELL_SIZE * m_direction,
		                                CELL_SIZE,
										CELL_SIZE,
										CELL_SIZE));

		i_window.draw(body);
	}
	//The "Maybe I am frightened" look.
	else if (m_frightened_mode == 1)
	{
		body.setColor(sf::Color(36, 36, 255));

		//The face remains the same regardless of where the ghost is going right now.
		face.setTextureRect(sf::IntRect(CELL_SIZE * 4,
		                                CELL_SIZE,
										CELL_SIZE,
										CELL_SIZE));

		if ((i_flash        == true) &&
		    (body_frame % 2 == 0))
		{
			body.setColor(sf::Color(255, 255, 255));
			face.setColor(sf::Color(255, 0, 0));
		}
		else
		{
			body.setColor(sf::Color(36, 36, 255));
			face.setColor(sf::Color(255, 255, 255));
		}

		i_window.draw(body);
	}
	//The "AAAAH!!!! I'M OUTTA HERE!!!!" look.
	else
	{
		//We only draw the face because Pacman stole the body.
		face.setTextureRect(sf::IntRect(CELL_SIZE * m_direction,
		                                CELL_SIZE * 2,
										CELL_SIZE,
										CELL_SIZE));
	}

	i_window.draw(face);

	//--------------------------------------<        This is to prevent overflowing.         >-
	m_animation_frame_timer = (m_animation_frame_timer + 1) % (GHOST_ANIMATION_FRAMES * GHOST_ANIMATION_SPEED);
}
