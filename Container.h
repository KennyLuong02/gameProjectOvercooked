#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <ctime>

using namespace std;

class Container {
    public:
        Container();
        Container(int state);

        void setState(int state);
        
        virtual int getState() = 0; //return soup sum
        

    protected:
        int state;
        bool isFull;
        time_t time; //might need to add in time_t later

        //friend class Player

        //In SFML there will be colour
        //Add in later

};

#endif