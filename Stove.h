#ifndef __STOVE_H__
#define __STOVE_H__

#include <string>
#include "Container.h"

using namespace std;

class Stove: public Container {
    public:
        Stove();
        int getState();
        void setState(int n);
        

    private:
        // int sum;
        

        //friend class Player

        //In SFML there will be colour
        //Add in later

};

#endif