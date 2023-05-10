#include <string>
#include "Container.h"
#include "Bowl.h"

using namespace std;

Bowl::Bowl() {
    Container::setState(0); //Initialise as empty bowl
    content = 0; //No soup inside
    //may need to set the inherited timer to 0
};

int Bowl::getState() {return state;};

void Bowl::setState(int state) {
    Container::setState(state); //Either 0: empty, 1:full, or -1: dirty
};

int Bowl::getState() {return state;};

void Bowl::setState(int content) {
    Container::setState(content); //Either 0: empty, 1:full, or -1: dirty
};
