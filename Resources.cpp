#include <string>
#include "Resources.h"
#include "Bowl.h"

using namespace std;

//Need some more work

Resources::Resources(): onion(100), tomato(100), mushroom(100) {
    bowlAmount = new Bowl*[3];
};

void Resources::removeOnion() {onion = onion - 1;};

void Resources::removeTomato() {tomato = tomato - 1;};

void Resources::removeMushroom() {mushroom = mushroom -1;};

int Resources::getOnion() {
    return onion;
}
int Resources::getTomato() {
    return tomato;
}
int Resources::getMushrooom() {
    return mushroom;
}
