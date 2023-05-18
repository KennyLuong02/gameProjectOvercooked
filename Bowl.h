#ifndef __BOWL_H__
#define __BOWL_H__
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
//////////////////////////////////////////////////////////////////////////////////////////////////////
// FOR THE BOWL
//
// [Bowl]
//      - Variables:
//          int state; (inherit from Container.h)
//          time_t time; (inherit from Container.h)
//          int content;
//      - Functions:

class Bowl: public Appliance {
    public:
        Bowl();

        int get_state();
        void set_state(int state);

        int get_content();
        void set_content(int contentt);

        void update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, MAP_WIDTH>& i_map, 
                    Bowl& i_bowl_1, Player& i_player); //may be virtual in Appliance
                    

        //reimplement virtual function from Appliance
        void reset();
        bool player_collide (const Position&  i_player_position);

        //learn to use this
        void draw(bool i_flash,sf::RenderWindow& i_window); //fix flash and learn render in sfml

        

    private:
        // int stateOfBowl;
        int content;
        

        //friend class Player

        //In SFML there will be colour
        //Add in later

};

#endif