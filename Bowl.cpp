#include <string>
#include "Container.h"
#include "Bowl.h"

using namespace std;

Bowl::Bowl() {
    Container::setState(0);
};

int Bowl::getState() {return state;};

void Bowl::setState(int n) {
    Container::setState(n);
};