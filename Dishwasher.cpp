#include <iostream>
#include <string>
#include "Player.h"
#include "Container.h"
#include "Dishwasher.h"

using namespace std;

Dishwasher::Dishwasher(): Container() {
    isOn = false; // If the dishwasher is empty
};

int Dishwasher::getState() {return state;};

void Dishwasher::setState(int n) {
    setPlayerState(n); //Either 0: empty, 1: full
};

bool Dishwasher::getPowerState() {return isOn;};

void Dishwasher::setPowerState(bool n) {
    isOn = n;
 };


void Dishwasher::timerFunction(Bowl* theBowl) { //need a Bowl input pointer
    //Check if the Dishwasher is empty
    if (state == 0) {
        //Wait 2s before make the bowl clean
        timeContainer = time(NULL);

        //If they Player want o access, deny
        time_t timeNow;
        timeNow = time(NULL) - timeContainer;
        cout << "Dishwashing in progress" << endl;

        while (timeNow < 2) {
            timeNow = time(NULL) - timeContainer;
            state = 1;
        }
        
        
        //Need a pointer to Bowl to change the state to dirty
        theBowl->setState(0);

    } else if (state == 1) {
        cout << "Dishwasher is full" << endl;
    }
};
