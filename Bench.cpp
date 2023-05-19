#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"
#include "Appliance.h"
#include "Bowl.h"
#include "Bench.h"

#include <SFML/Graphics.hpp>

using namespace std;

Bench::Bench() {
    Appliance();
    m_id = 0;
}

Bench::Bench(unsigned char i_id) {
    Appliance(i_id);
}

int Bench::get_state() {return get_state();};

void Bench::set_state(int state) {set_state(state);};

void Bench::reset() {
	state = 0;
	m_animation_frame_timer  = 0;
}

///////////////////////////////
//Change this to the range of the Bench and Player position
bool Bench::player_collide(const Position& i_player_position) { //if the player is in the assign position and press a key then do this
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

void Bench::update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, 
                    MAP_WIDTH>& i_map, Bench& i_bench, Bowl& i_bowl_1, Player& i_player) {
    
    Position thePlayer = i_player.get_position();
    int x_player_position = thePlayer.x;
    int y_player_position = thePlayer.y;

    Position theBowl = i_bowl_1.get_position();
    int x_bowl_position = theBowl.x;
    int y_bowl_position = theBowl.y;

    int x_bench_position = m_position.x;
    int y_bench_position = m_position.y;

    //Everything in the Bench will work only if the Player is in range
    //Check if the position of the Player is inside the range of the Bench
    //Implement player_collide
    if (player_collide(i_player.get_position()) == true) {

    //Always display this if the Player is inside the range of the Bench
    cout << "Try 'D' to drop" << endl;
    cout << "Try 'P' to pick up " << endl;

    //If the Player want to drop anything on the Bench
    //Check if the key 'D' is pressed and Bench is empty
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) == true) && 
            (i_bench.get_state() == 0)) { //if it is empty
        
        //check if that is a Bowl then make the position of Bowl equal to Bench
        if ((i_player.get_state() == -1) || (i_player.get_state() == 1) || 
                (i_player.get_state() == 15) || (i_player.get_state() == 21) || 
                    (i_player.get_state() == 33) || (i_player.get_state() == 23)) {
            i_bowl_1.set_position(x_bench_position,y_bench_position);
            i_bench.set_state(i_player.get_state());
            i_player.set_state(0); //then Player hand is empty

            //may have to do each case separately to render different stages
            //of Bowl

        } else if ((i_player.get_state() == 5) || (i_player.get_state() == 7) || 
                (i_player.get_state() == 11)) {
            //check if that is mushroom, or onion... 
            //then make the state of Bench equal to that
            i_bench.set_state(i_player.get_state());
            i_player.set_state(0); //then Player hand is empty

            //may have to do each case separately to render different food
        }
    }

    //If the Player want to pick up thing from the Bench
    //Check if the key 'P' is pressed and Bench is not empty
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::P) == true) && 
            (i_bench.get_state() != 0)) { //maybe true
        
        //check if the thing is a Bowl
        if ((i_bench.get_state() == -1) || (i_bench.get_state() == 1) || 
                (i_bench.get_state() == 15) || (i_bench.get_state() == 21) || 
                    (i_bench.get_state() == 33) || (i_bench.get_state() == 23)) {
            
            //change the Bowl position to the Player
            i_bowl_1.set_position(x_player_position,y_player_position);
            //change the state of the Player to the Bowl
            i_player.set_state(i_bowl_1.get_state());
            //then make the state of Bench empty
            i_bench.set_state(0);

        } else if ((i_player.get_state() == 5) || (i_player.get_state() == 7) || 
                    (i_player.get_state() == 11)) {
            //check if that is mushroom, or onion... 
            //then make the state of Player equal to that
            i_player.set_state(i_bench.get_state());
            //then make the state of Bench empty
            i_bench.set_state(0);
        }
    }
    }
}

void Bench::draw(bool i_flash,sf::RenderWindow& i_window) {
    
}
