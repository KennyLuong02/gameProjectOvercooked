#ifndef __APPLIANCEMANAGER_H__
#define __APPLIANCEMANAGER_H__
#include <string>
#include <array>
#include <cmath>
#include "Position.h"
#include "CSprite.h"
#include "Player.h"
#include "Appliance.h"
#include "Bench.h"
#include "Bin.h"
#include "Bowl.h"
#include "Dishwasher.h"
#include "Mushroom.h"
#include "Onion.h"
#include "Order.h"
#include "Stove.h"

#include <SFML/Graphics.hpp>

class ApplianceManager {
    public:
        ApplianceManager();

        void draw  (bool i_flash, sf::RenderWindow& i_window);

        void reset (unsigned char i_level, const std::array<Position, 10>& i_appliance_positions);
        void update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, 
                        MAP_WIDTH>& i_map, Player& i_player);

    private:
        std::array<Appliance, 10> m_ghosts;

        //The ghosts will switch between the scatter mode and the chase mode before permanently chasing Pacman.
        //So we need this to keep track of the waves.
        unsigned char        m_current_wave;

        //Damn, I really used a lot of timers.
        unsigned short       m_wave_timer;
};

#endif