#include <string>
#include "Player.h"
#include "Container.h"
#include "Stove.h"

using namespace std;

Stove::Stove(): Container() {
    content = 0;
};

int Stove::getState() {return state;};

void Stove::setState(int n) {
    setPlayerState(n);
};

int Stove::getContent() {return content;};

void Stove::setContent(int content) {
   this -> content = content;
};