#include <string>
#include "Container.h"

using namespace std;


// Need some more work


Container::Container(): state(0) {}; //may need to set the timer
                                     //likely don't

Container::Container(int state): state(state) {}; //may need to set the timer
                                                  //likely don't

void Container::setState(int state) {
    this-> state = state;
};