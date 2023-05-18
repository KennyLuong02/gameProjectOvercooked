#include "Position.h"

class CSprite {
public:
                   CSprite                  ();

	void           set_position             (int i_x,int i_y);
	Position       get_position             ();

	virtual int get_state() = 0;
    virtual void set_state(int stateInput) = 0;

	virtual void reset() = 0;
	
	//may not need these for Appliance
	// virtual bool map_collide(bool i_collect_pellets, bool i_use_door, 
	// 							int i_x,  int i_y, std::array<std::array<ObjectType, 
	// 							MAP_HEIGHT>, MAP_WIDTH>& i_map) = 0;

protected:
	int state;
	Position       m_position;
};