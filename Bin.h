#ifndef __BIN_H__
#define __BIN_H__
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Appliance.h"
#include "Player.h"
#include "Bowl.h"

#include <SFML/Graphics.hpp>

using namespace std;

class Bin: public Appliance  {
    public:
        Bin();

        int get_state();
        void set_state(int n);

	    void update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, MAP_WIDTH>& i_map, 
                    Bowl& i_bowl_1, Player& i_player);

        //reimplement virtual function from Appliance
        void reset();
        bool player_collide (const Position&  i_player_position);
        void draw(bool i_flash,sf::RenderWindow& i_window);

};

#endif
