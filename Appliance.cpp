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





///////////////////////////////////////////////////////////////////////////////
///Fix this
void Appliance::update(unsigned char                                            i_level,
                   std::array<std::array<ObjectType, MAP_HEIGHT>, MAP_WIDTH>& i_map,
				   Appliance&                                                   i_ghost_0,
				   Player&                                                  i_pacman)
{
	//Can the ghost move?
	bool move = 0;

	//If this is greater than 1, that means that the ghost has reached the intersection.
	//We don't consider the way back as an available way.
	unsigned char available_ways = 0;

	unsigned char speed          = GHOST_SPEED;

	std::array<bool, 4> walls{};

	//I used the modulo operator in case the ghost goes outside the grid.
	if ((m_frightened_mode                 == 2) &&
	    (m_position.x % GHOST_ESCAPE_SPEED == 0) &&
		(m_position.y % GHOST_ESCAPE_SPEED == 0))
	{
		speed = GHOST_ESCAPE_SPEED;
	}

	update_target(i_pacman.get_direction(),
	              i_ghost_0.get_position(),
				  i_pacman.get_position());

	//This is so clean! I could spend hours staring at it.
	walls[0] = map_collision(0, m_use_door, m_position.x + speed, m_position.y,         i_map);
	walls[1] = map_collision(0, m_use_door, m_position.x,         m_position.y - speed, i_map);
	walls[2] = map_collision(0, m_use_door, m_position.x - speed, m_position.y,         i_map);
	walls[3] = map_collision(0, m_use_door, m_position.x,         m_position.y + speed, i_map);

	if (m_frightened_mode != 1)
	{
		//I used 4 because using a number between 0 and 3 will make the ghost move in a direction it can't move.
		unsigned char optimal_direction = 4;

		//The ghost can move.
		move = 1;

		for (unsigned char a = 0; a < 4; a++)
		{
			//Ghosts can't turn back! (Unless they really have to)
			if (a == (2 + m_direction) % 4)
			{
				continue;
			}
			else if (walls[a] == 0)
			{
				if (optimal_direction == 4)
				{
					optimal_direction = a;
				}

				available_ways++;

				if (get_target_distance(a) < get_target_distance(optimal_direction))
				{
					//The optimal direction is the direction that's closest to the m_target_pos.
					optimal_direction = a;
				}
			}
		}

		if (available_ways > 1)
		{
			//When the ghost is at the intersection, it chooses the optimal direction.
			m_direction = optimal_direction;
		}
		else
		{
			if (optimal_direction == 4)
			{
				//"Unless they have to" part.
				m_direction = (2 + m_direction) % 4;
			}
			else
			{
				m_direction = optimal_direction;
			}
		}
	}
	else
	{
		//I used rand() because I figured that we're only using randomness here, and there's no need to use a whole library for it.
		unsigned char random_direction = rand() % 4;

		if (m_frightened_speed_timer == 0)
		{
			//The ghost can move after a certain number of frames.
			move = 1;

			m_frightened_speed_timer = GHOST_FRIGHTENED_SPEED;

			for (unsigned char a = 0; a < 4; a++)
			{
				//They can't turn back even if they're frightened.
				if (a == (2 + m_direction) % 4)
				{
					continue;
				}
				else if (walls[a] == 0)
				{
					available_ways++;
				}
			}

			if (available_ways > 0)
			{
				while ((walls[random_direction] == 1)              ||
				       (random_direction == (2 + m_direction) % 4))
				{
					//We keep picking a random direction until we can use it.
					random_direction = rand() % 4;
				}

				m_direction = random_direction;
			}
			else
			{
				//If there's no other way, it turns back.
				m_direction = (2 + m_direction) % 4;
			}
		}
		else
		{
			m_frightened_speed_timer--;
		}
	}

	//If the ghost can move, we move it.
	if (move == 1)
	{
		switch (m_direction)
		{
			case 0:
			{
				m_position.x += speed;

				break;
			}
			case 1:
			{
				m_position.y -= speed;

				break;
			}
			case 2:
			{
				m_position.x -= speed;

				break;
			}
			case 3:
			{
				m_position.y += speed;
			}
		}

		//Warping.
		//When the ghost leaves the map, we move it to the other side.
		if (m_position.x <= -CELL_SIZE)
		{
			m_position.x = CELL_SIZE * MAP_WIDTH - speed;
		}
		else if (m_position.x >= CELL_SIZE * MAP_WIDTH)
		{
			m_position.x = speed - CELL_SIZE;
		}
	}

	if (pacman_collision(i_pacman.get_position()) == true)
	{
		//When the ghost is not frightened and collides with Pacman, we kill Pacman.
		if (m_frightened_mode == 0) 
		{
			i_pacman.set_am_I_dead(true);
		}
		else //Otherwise, the ghost starts running towards the house.
		{
			m_use_door = true;

			m_frightened_mode = 2;

			m_target_pos = m_home_pos;
		}
	}
}
