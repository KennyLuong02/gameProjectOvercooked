#include <string>
#include <ctime>
#include "Container.h"

using namespace std;


// Need some more work


Container::Container(): Player() { //the state 0 is already initialised when make the Container by Player
    timeContainer = time(NULL);
};