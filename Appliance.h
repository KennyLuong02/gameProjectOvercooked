#ifndef __APPLIANCE_H__
#define __APPLIANCE_H__
#include <string>
#include "Position.h"
#include "CSprite.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
// FOR THE APPLIANCE
//
// [Appliance]
//      - Variables:
//          bool state;
//          string name;
//      - Functions:

enum AppObject
{
  APP_DEFAULT,
  APP_STOVE,
  APP_DISHWASHER,
  APP_BOWL
};

class Appliance: public CSprite {
    public:
        Appliance();
        Appliance(unsigned char i_id);  //may use int

        int get_state();
        void set_state(int state);
        
	      void update(unsigned char i_level, std::array<std::array<ObjectType, MAP_HEIGHT>, MAP_WIDTH>& i_map, 
                    Appliance& i_ghost_0, Player& i_player); //fix this and this can be made into virtual function

        //virtual function
        virtual void reset();
	      virtual bool player_collide (const Position&  i_player_position);

        //learn to use this
        void draw(bool i_flash,sf::RenderWindow& i_window); //fix flash and learn render in sfml


    protected:
        int state;
        // bool isFull
        time_t timeContainer; //check

	    unsigned short m_animation_frame_timer;


        //don't know
        unsigned char  m_id;
	    //The ghost will go here when escaping.
	    Position m_home_pos;
	    //You can't stay in your house forever (sadly).
	    Position m_home_exit_pos;
	    //Current m_target_pos.
	    Position m_target_pos;

};

#endif
