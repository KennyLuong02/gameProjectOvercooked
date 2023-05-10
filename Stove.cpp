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

//Not sure if Content is needed
int Stove::getContent() {return content;};

void Stove::setContent(int content) {
   this -> content = content;
};
