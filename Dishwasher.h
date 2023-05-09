#ifndef __DISHWASHER_H__
#define __DISHWASHER_H__
#include <string>
#include "Container.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////
// FOR THE DISHWASHER
//
// [Dishwasher]
//      - Variables:
//          int state; (inherit from Container.h)
//          time_t time; (inherit from Container.h)
//          bool isOn;
//      - Functions:
//          Dishwasher();
//          int getState();
//          void setState(int n);
//          bool getPowerState();
//          void setPowerState(bool n);
//
// Description:
// It will take the bowl from the Order.h as dirty (state of bowl -1) and change the bowl to clean (state of bowl 0) (take 5 seconds)
// It will also change from empty (state od Dishwasher 0) to full (state of Dishwasher 1) (immediately)
// It will take 5 seconds to make these changes
// If there is more bowl from the Order.h while it is full, it take the bowl and will warn the player and leave extra bowl unwashed
// The player has to turn the Dishwasher on manually if they want to wash the bowl
//
//
// It will have two states: (inherited from Container.cpp)
//              0: empty
//              1: full
//
// It will have a signal isOn:
//              0: off
//              1: on
//
// It will also have a time factor
//              5 seconds to finish up washing a bowl
//
// It will start at state: 0
// 
// It will have funtions: int getState(): return the state
//                        void setState(int n): set the state
//
// 
// For void setState(int n): interact with Order.h (when the bowl is always dirty):
//                                           when the bowl is dirty: 
//
//                     interact with Player.h (when the bowl is empty, full, dirty):
//                                           when the bowl is empty: put food in (only soup, no raw food)
//                                           when the bowl is full: cannot put food in
//                                           when the bowl is dirty: cannot happen
//                                                                   because all dirty bowl will go straight to the dish washer
//
//                     interact with Resources.h (when the bowl is empty, full, dirty):
//                                           when the bowl is empty: cannot put raw food
//                                           when the bowl is full: cannot put food in
//                                           when the bowl is dirty: cannot happen
//                                                                   because all dirty bowl will go straight to the dish washer
//
//                     (maybe: interact with Stove.h (when the bowl is empty, full, dirty))
//
// Kenny: not sure if we have to make 3 bowls in an array when contruct the Resources in Resources.h
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class Dishwasher: public Container {
    public:
        Dishwasher(); //Initialise with an array of 3 empty spots to hold the bowls
        int getState();
        void setState(int n);

        bool getPowerState();
        void setPowerState(bool n);
        

    private:
        bool isOn;
        

        //friend class Player

        //In SFML there will be colour
        //Add in later

};

#endif