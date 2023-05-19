#ifndef __APPLIANCE_H__
#define __APPLIANCE_H__
#include <string>
#include "Position.h"
#include "CSprite.h"

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
        Appliance(unsigned char i_id);

        int get_state();
        void set_state(int state);

        //virtual function
        virtual void reset();
        //virtual pure function
	      virtual bool player_collide(const Position& i_player_position);
        virtual void draw(bool i_object,sf::RenderWindow& i_window);

  protected:
    unsigned short m_animation_frame_timer;
    unsigned char  m_id;

};

#endif
