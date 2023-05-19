#ifndef __STOVE_H__
#define __STOVE_H__
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"
#include "Appliance.h"
#include "Bowl.h"

#include <SFML/Graphics.hpp>

using namespace std;

class Stove: public Appliance {
    public:
        Stove();

        int get_state();
        void set_state(int n);

        int get_content();
        void set_content(int content);

        bool get_cooking_state();
        void set_cooking_state(bool cook_yet);

        void add_content(int contentToAdd);

	    void update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, MAP_WIDTH>& i_map, 
                    Stove& i_stove, Bowl& i_bowl_1, Player& i_player, int content_to_add); //fix this and this can be made into virtual function);

        //reimplement virtual function from Appliance
        void reset();
        bool player_collide (const Position&  i_player_position);
        void draw(bool i_flash,sf::RenderWindow& i_window);

    private:
        int content;
        bool is_it_cooked;

};

#endif
