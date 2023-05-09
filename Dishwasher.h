#ifndef __DISHWASHER_H__
#define __DISHWASHER_H__

#include <string>
#include "Container.h"

using namespace std;

class Dishwasher: public Container {
    public:
        Dishwasher();
        int getState();
        void setState(int n);
        

    private:
        // int sum;
        

        //friend class Player

        //In SFML there will be colour
        //Add in later

};

#endif