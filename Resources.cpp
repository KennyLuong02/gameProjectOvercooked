#include <string>
#include "Resources.h"
#include "Bowl.h"

using namespace std;

//Need some more work

// Resources::Resources(): onion(100), tomato(100), mushroom(100) {
//     bowlAmount = new Bowl*[3];
// };

Resources::Resources(): onion(100), tomato(100), mushroom(100) {
    mushroom = 100;
    onion = 100;
    tomato = 100;
    bowlAmount = new Bowl*[3];
};

// void Resources::removeOnion() {onion = onion - 1;};

// void Resources::removeTomato() {tomato = tomato - 1;};

// void Resources::removeMushroom() {mushroom = mushroom -1;};

int Resources::getOnion() {
    return onion;
}
int Resources::getTomato() {
    return tomato;
}
int Resources::getMushrooom() {
    return mushroom;
}

void Resources::pickUp(string pickUpInput) {
    if (pickUpInput == "Bowl") {
        setPlayerState(1);
    } else if (pickUpInput == "Mushroom") {
        setPlayerState(5);
        mushroom = mushroom -1;
    } else if (pickUpInput == "Onion") {
        setPlayerState(7);
        onion = onion - 1;
    } else if (pickUpInput == "Tomato") {
        setPlayerState(11);
        tomato = tomato - 1;
    }
};
