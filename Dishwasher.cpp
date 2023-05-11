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

void Dishwasher::timerFunction() {
    //Check if the Dishwasher is empty
    if (state == 0) {
        //Wait 2s before make the bowl clean
        time_t timeNow;
        timeNow = time(NULL) - timeContainer;

        while (timeNow < 2) {
            timeNow = time(NULL) - timeContainer;
        }
        
        //Need a pointer to Bowl to change the state to dirty

    } else if (state == 1) {
        cout << "Dishwasher is full" << endl;
    }
};