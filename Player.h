#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>

using namespace std;

class Player {
    public:
        void useStove(); //
        void useDishwasher(); //
        void useBowl(); //


        void pickupOnion();
        void pickupTomato();
        void pickupMushroom();
        
        void pickupBowl();

    private:
        string state; //maybe int


};

#endif