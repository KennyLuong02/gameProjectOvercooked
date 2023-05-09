#include <string>
#include "Container.h"
#include "Dishwasher.h"

using namespace std;

Dishwasher::Dishwasher() {
    Container::setState(0);
};

int Dishwasher::getState() {return state;};

void Dishwasher::setState(int n) {
    Container::setState(n);
};