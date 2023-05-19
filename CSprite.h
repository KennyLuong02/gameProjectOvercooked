#ifndef __CSPRITE_H__
#define __CSPRITE_H__

#include "Position.h"

#include <SFML/Graphics.hpp>

class CSprite {
public:
    CSprite();

	void  set_position (int i_x,int i_y);
	Position get_position ();

	virtual int get_state() = 0;
    virtual void set_state(int stateInput) = 0;

	virtual void reset() = 0;

protected:
	int state;
	Position m_position;
};

#endif