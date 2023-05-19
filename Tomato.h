#ifndef __TOMATO_H__
#define __TOMATO_H__
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Appliance.h"
#include "Player.h"

#include <SFML/Graphics.hpp>

using namespace std;

class Tomato: public Appliance  {
    public:
        Tomato();

        int get_tomato_amount();
        void set_tomato_amount(int n);

	    void update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, MAP_WIDTH>& i_map, 
                    Player& i_player);

        //reimplement virtual function from Appliance
        void reset();
        bool player_collide (const Position&  i_player_position);
        void draw(bool i_flash,sf::RenderWindow& i_window);

    private:
        int tomato_amount;
};

#endif
