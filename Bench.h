#ifndef __BENCH_H__
#define __BENCH_H__
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

class Bench: public Appliance {
    public:
        Bench();
        Bench(unsigned char i_id);
        
        int get_state();
        void set_state(int n);

        void update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, MAP_WIDTH>& i_map, 
                    Bench& i_bench, Bowl& i_bowl_1, Player& i_player);
                    // Seht work on the display for Player options

        //reimplement virtual function from Appliance
        void reset();
        bool player_collide(const Position&  i_player_position); //Ansh and Seth work on this
        void draw(bool i_flash,sf::RenderWindow& i_window); //nsh and Seth work on this


    private:
        unsigned char m_id;
        

        //friend class Player

        //In SFML there will be colour
        //Add in later

};

#endif