#include <iostream>
#include <string>
#include "Kitchen.h"
#include "Player.h"

// Need some more work


Player::Player(std::string nameInput) : name(nameInput) {
    state = 0;
};

Player::Player() : Player("No Name") {};


void Player::drop() {
    if(state == 5 || state == 7 || state == 11) { //The rest of the pickup would be in Resources
        this->setPlayerState(0);
        std::cout << "dropped" << std::endl;
    }   else {
        std::cout << "not dropped" << std::endl;
        return;
    }
};

void Player::setPlayerState(int stateInput) {
    state = stateInput;
};
int Player::getPlayerState() {
    return state;
};



void Player::setPlayerName(std::string nameInput) {
    name = nameInput;
};
std::string Player::getPlayerName() {
    return name;
};


