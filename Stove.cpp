#include <string>
#include "Container.h"
#include "Stove.h"

using namespace std;

Stove::Stove() {
    Container::setState(0);
};

int Stove::getState() {return state;};

void Stove::setState(int n) {
    Container::setState(n);
};