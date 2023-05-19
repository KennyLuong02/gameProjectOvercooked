#ifndef __MUSHROOM_H__
#define __MUSHROOM_H__
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"

#include <SFML/Graphics.hpp>

using namespace std;

class Mushroom: public CSprite  {
    public:
        Mushroom();

        int get_mushroom_amount();
        void set_mushroom_amount(int n);

	    void update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, MAP_WIDTH>& i_map, 
                    Player& i_player); //fix this and this can be made into virtual function);

        //reimplement virtual function from Appliance
        void reset();
        bool player_collide (const Position&  i_player_position);

        //learn to use this
        void draw(bool i_flash,sf::RenderWindow& i_window); //fix flash and learn render in sfml

    private:
        int mushroom_amount;
};

#endif
