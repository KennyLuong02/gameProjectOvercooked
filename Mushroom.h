#ifndef __MUSHROOM_H__
#define __MUSHROOM_H__
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Appliance.h"
#include "Player.h"

#include <SFML/Graphics.hpp>

using namespace std;

class Mushroom: public Appliance {
    public:
        Mushroom();

        int get_mushroom_amount();
        void set_mushroom_amount(int n);

	    void update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, MAP_WIDTH>& i_map, 
                    Player& i_player);

        //reimplement virtual function from Appliance
        void reset();
        bool player_collide (const Position&  i_player_position);
        void draw(bool i_flash,sf::RenderWindow& i_window);

    private:
        int mushroom_amount;
};

#endif
