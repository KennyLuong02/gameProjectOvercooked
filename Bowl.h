#ifndef __BOWL_H__
#define __BOWL_H__

#include <string>
#include "Container.h"

using namespace std;

class Bowl: public Container {
    public:
        Bowl();
        int getState();
        void setState(int n);
        

    private:
        int sum;
        

        //friend class Player

        //In SFML there will be colour
        //Add in later

};

#endif