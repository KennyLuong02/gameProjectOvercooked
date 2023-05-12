#include <iostream>
#include <string>
#include "Container.h"
#include "Bowl.h"

using namespace std;


// Need some more work


Bowl::Bowl() {
    state = 0; //Initialise as empty bowl
    content = 0; //No soup inside
    //may need to set the inherited timer to 0
};

int Bowl::getState() {return state;};

void Bowl::setState(int state) {
    stateOfBowl = state; //Either 0: empty, 1:full, or -1: dirty
};

int Bowl::getContent() {return content;};

void Bowl::setContent(int contentt) {
    if (contentt == 0 || contentt == 15 || contentt == 21 || contentt == 33 || contentt == 23) {
        this-> content = content; //Either 0: empty, 15: Mushroom soup, 21: Onion soup, 33: Tomato soup, 23: Com soup
    } else {
        cout << "Cannot put this into the bowl" << endl; //need to change it in the SFML version
    }
};
