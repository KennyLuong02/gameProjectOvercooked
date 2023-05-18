#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include "Position.h"
#include "CSprite.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
// FOR THE PLAYER
//
// [Player]
//      - Variables:
//          bool state;
//          string name;
//      - Functions:
//          void useStove();
//          void useDishwasher();
//          void useBowl();
//          void useBin();


class Player: public CSprite{
    public:
        Player();
        Player(std::string);

        int get_state();
        void set_state(int stateInput);

        std::string get_player_name();
        void set_player_name(std::string nameInput);

        void set_animation_frame_timer(unsigned short i_animation_frame_timer);
        unsigned short get_animation_frame_timer();

        void update(unsigned char i_level, std::array<std::array<ObjectType,
                         MAP_HEIGHT>, MAP_WIDTH>& i_map);

        //reimplement virtual function                 
        void reset();

        //learn to use this
        bool will_i_collide(bool i_collect_pellets, bool i_use_door, 
                            short i_x, short i_y, std::array<std::array<ObjectType, 
                                MAP_HEIGHT>, MAP_WIDTH>& i_map);

        void draw(bool i_victory, sf::RenderWindow& i_window);

        void bin(); //make a Bin class later


        //don't know
        unsigned char get_direction();
        void set_direction(unsigned char i_direction);
	    void set_dead(bool i_dead);
        bool get_animation_over();
	    void set_am_I_dead(bool i_am_I_dead);
	    bool get_am_I_dead();

	


    protected:
        int state;
        std::string name;

        unsigned char  m_direction;

	    unsigned short m_animation_frame_timer;

	    //unsigned short m_energizer_timer; no need

        //Already in CSprite
        //Position m_position;


        //don't know
        //This is used for the death animation.
	    bool m_animation_over;
	    //Am I dead?
	    bool m_dead;

};

#endif
