#ifndef __ORDER_H__
#define __ORDER_H__
#include <string>

using namespace std;

class Order {
    public:
        void putOrder(); //
        int receiveOrder(int sum); //check if the soup is correct
                                    //if yes then delete the order and empty the bowl
                                    //if no then keep all order and empty the bowl
                                    //return dirty bowl
        

    private:
        string state;


};

#endif