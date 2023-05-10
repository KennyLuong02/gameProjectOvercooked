#include <iostream>
#include <string>
#include "Kitchen.h"
#include "Player.h"

using namespace std;


// Need some more work


Player::Player() {


    //may need to add all the instruction and details of the game here


    cout << "Please enter your name: ";
    cin >> name;

    state = 0; //start as empty

}