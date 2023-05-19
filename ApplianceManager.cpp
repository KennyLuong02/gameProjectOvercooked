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
#include "Tomato.h"
#include "ApplianceManager.h"

#include <SFML/Graphics.hpp>

// ApplianceManager::ApplianceManager() :
// 	m_appliance      ({Appliance(0),
// 	                Ghost(1),
// 					Ghost(2),
// 					Ghost(3)}),
// 	m_current_wave(0),
// 	m_wave_timer  (LONG_SCATTER_DURATION) {}

ApplianceManager::ApplianceManager() {
	m_appliance = new Appliance*[10];

	m_appliance[0] = new Bench();
	m_appliance[1] = new Bench();
	m_appliance[2] = new Bench();

	m_appliance[3] = new Bin();
	m_appliance[4] = new Bowl();
	m_appliance[5] = new Dishwasher();
	m_appliance[6] = new Mushroom();
	m_appliance[7] = new Onion();
	m_appliance[8] = new Stove();
	m_appliance[9] = new Tomato();

}

Appliance** ApplianceManager::get_appliance_manager() {
	return m_appliance;
}


// void ApplianceManager::draw(bool              i_flash,
//                         		sf::RenderWindow& i_window) {
// 	for (Appliance& appliance : m_appliance)
// 	{
// 		ghost.draw(i_flash, i_window);
// 	}
// }

void ApplianceManager::draw(bool i_flash,
                        		sf::RenderWindow& i_window) {
	for (int i = 0; i < 10; i++) {
		//Figure out the draw function
		m_appliance[i]->draw();
	}
}

void ApplianceManager::reset() {

	for (int i = 0; i < 10; i++) {
		m_appliance[i]->reset();
	}

}

void ApplianceManager::update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, MAP_WIDTH>& i_map,
						  		Bench& i_bench, Dishwasher& i_dishwasher, Stove& i_stove, Bowl& i_bowl_1, Player&  i_player, 
						  			int content_to_add) {
	// ApplianceManager myFleet = Fleet();
	// Car** pCarFleet = myFleet.get_fleet();
	m_appliance[0]->update(i_level, i_map, i_bench, i_bowl_1, i_player);
	m_appliance[1]->update(i_level, i_map, i_bench, i_bowl_1, i_player);
	m_appliance[2]->update(i_level, i_map, i_bench, i_bowl_1, i_player);
	
	m_appliance[3]->update(i_level, i_map, i_bowl_1, i_player);
	m_appliance[4]->update(i_level, i_map, i_bowl_1, i_player);
	m_appliance[5]->update(i_level, i_map, i_dishwasher, i_bowl_1, i_player);
	m_appliance[6]->update(i_level, i_map, i_player);
	m_appliance[7]->update(i_level, i_map, i_player);
	m_appliance[8]->update(i_level, i_map, i_stove, i_bowl_1, i_player, content_to_add);
	m_appliance[9]->update(i_level, i_map, i_player);
}