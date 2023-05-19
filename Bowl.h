#ifndef __BOWL_H__
#define __BOWL_H__
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"
#include "Appliance.h"

#include <SFML/Graphics.hpp>

using namespace std;

class Bowl: public Appliance {
    public:
        Bowl();

        int get_state();
        void set_state(int state);

        int get_content();
        void set_content(int contentt);

        void update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, MAP_WIDTH>& i_map, 
                    Bowl& i_bowl_1, Player& i_player);
                    

        //reimplement virtual function from Appliance
        void reset();
        bool player_collide (const Position&  i_player_position);
        void draw(bool i_flash,sf::RenderWindow& i_window);

        

    private:
        int content;

};

#endif