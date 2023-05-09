#ifndef __RESOURCES_H__
#define __RESOURCES_H__

using namespace std;

#include "Bowl.h"

class Resources {
    public:
        Resources();
        void removeOnion();
        void removeTomato();
        void removeMushroom();

    private:
        int mushroom; //number 5
        int onion; //number 7
        int tomato; //number 11
        Bowl* bowlAmount;

        //friend class Player

        //In SFML there will be colour
        //Add in later

};

#endif