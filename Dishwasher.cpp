#include <string>
#include "Container.h"
#include "Dishwasher.h"

using namespace std;

Dishwasher::Dishwasher() {
    Container::setState(0); //Initialize as empty dishwasher
    isOn = false; // If the dishwasher is empty
};

int Dishwasher::getState() {return state;};

void Dishwasher::setState(int n) {
    Container::setState(n); //Either 0: empty, 1: full
};

bool Dishwasher::getPowerState() {return isOn;};

void Dishwasher::setPowerState(bool n) {
    isOn = n;
 };
