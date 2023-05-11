#include <iostream>
#include <string>
#include <ctime>
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
   this-> content = content;
};




void Stove::timerFunction(int contentToAdd) { //need to add input of the content as addContent()
    content = content + contentToAdd;
    //Check if the sum is higher than 14
    if (content > 14) {
        //Wait 3s before release the content
        time_t timeNow;
        timeNow = time(NULL);
        timeNow = timeNow - timeContainer;
        cout << "Cooking in progress" << endl;

        while (timeNow < 3) {
            timeNow = time(NULL);
            timeNow = timeNow - timeContainer;
        }

        //Make the content to the soup sum
        //Use getContent to put soup in Bowl
        //If the Bowl get the content then setContent(0)
    }
};