#ifndef __ORDER_H__
#define __ORDER_H__
#include <string>
#include "Bowl.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////
// FOR THE ORDER
//
// [Order]
//      - Variables:
//          int order;
//      - Functions:
//          void putOrder();
//          void checkOrder();
//          int receiveOrder(int sum);
//
// Description:
// It will take the bowl from the Order.h as dirty (state of bowl -1) and change the bowl to clean (state of bowl 0) (take 5 seconds)
// It will also change from empty (state od Dishwasher 0) to full (state of Dishwasher 1) (immediately)
// It will take 5 seconds to make these changes
// If there is more bowl from the Order.h while it is full, it take the bowl and will warn the player and leave extra bowl unwashed
// The player has to turn the Dishwasher on manually if they want to wash the bowl
//
//
// It will have two states: (inherited from Container.cpp)
//              0: empty
//              1: full
//
// It will have a signal isOn:
//              0: off
//              1: on
//
// It will also have a time factor
//              5 seconds to finish up washing a bowl
//
// It will start at state: 0
// 
// It will have funtions: int getState(): return the state
//                        void setState(int n): set the state
//
// 
// For void setState(int n): interact with Order.h (when the bowl is always dirty):
//                                           when the bowl is dirty: 
//
//                     interact with Player.h (when the bowl is empty, full, dirty):
//                                           when the bowl is empty: put food in (only soup, no raw food)
//                                           when the bowl is full: cannot put food in
//                                           when the bowl is dirty: cannot happen
//                                                                   because all dirty bowl will go straight to the dish washer
//
//                     interact with Resources.h (when the bowl is empty, full, dirty):
//                                           when the bowl is empty: cannot put raw food
//                                           when the bowl is full: cannot put food in
//                                           when the bowl is dirty: cannot happen
//                                                                   because all dirty bowl will go straight to the dish washer
//
//                     (maybe: interact with Stove.h (when the bowl is empty, full, dirty))
//
// Kenny: not sure if we have to make 3 bowls in an array when contruct the Resources in Resources.h
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class Order {
    public:
        Order(int orderInput);
        void putOrder();
        void checkOrder();
        int receiveOrder(Bowl* theBowl); //check if the soup is correct
                                    //if yes then delete the order and empty the bowl
                                    //if no then keep all order and empty the bowl
                                    //return dirty bowl
        

    private:
        int* order; //change the size later
        int orderSize; //keep the size of the order array

        int counter; //to keep track of how many order has been placed 
        int contentOfBowl; //to get content from bowl

        int contentOfOrder; //may not need this
                            //this is to compare with the content inside the bowl


};

#endif