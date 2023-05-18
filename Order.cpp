#include <iostream>
#include <string>
#include <unistd.h>
#include "Order.h"
#include "Bowl.h"

using namespace std;


// Need some more work


Order::Order(int orderInput) : orderSize(orderInput) {
    //This can be randomised later in the game but it will be hard-code for now

    int array[5] = {15,21,33,23,21};
    order = &array[0];

    counter = 0;
}

void Order::putOrder() {
    //This for-loop can be use again later and should be fine
    for (int i = 0; i < orderSize; i++) {
        if (order[i] == 15) {
            cout << "Mushroom soup: include 3 mushrooms" << endl;
        } else if (order[i] == 21) {
            cout << "Onion soup: include 3 onions" << endl;
        } else if (order[i] == 33) {
            cout << "Tomato soup: include 3 tomatoes" << endl;
        } else if (order[i] == 23) {
            cout << "Combination soup: include 1 of each veges" << endl;
        }

        //To check for bug later
        else {cout << "An error is here in the Order" << endl; break;}

        counter++;
        sleep(10);
    }

};

void Order::checkOrder() {
    for (int i = 0; i < counter; i++) {
        if (order[i] == 15) {
            cout << "Mushroom soup: include 3 mushrooms" << endl;
        } else if (order[i] == 21) {
            cout << "Onion soup: include 3 onions" << endl;
        } else if (order[i] == 33) {
            cout << "Tomato soup: include 3 tomatoes" << endl;
        } else if (order[i] == 23) {
            cout << "Combination soup: include 1 of each veges" << endl;
        }
    }
};

int Order::receiveOrder(Bowl* theBowl) { //The content is received from the Bowl
    contentOfBowl = theBowl->getContent(); //Get the bowl content
    if (contentOfBowl == 0) {
        theBowl->setState(-1);
        return 0; //check if there is something else to return back 
    }
    for (int i = 0; i < counter; i++) {
        if (order[i] == contentOfBowl) {
            order[i] = NULL;
            theBowl->setState(-1);
            break;

        } else if (order[i] == contentOfBowl) {
            order[i] = NULL;
            theBowl->setState(-1);
            break;

        } else if (order[i] == contentOfBowl) {
            order[i] = NULL;
            theBowl->setState(-1);
            break;

        } else if (order[i] == contentOfBowl) {
            order[i] = NULL;
            theBowl->setState(-1);
            break;

        }
    }
};