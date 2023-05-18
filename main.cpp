#include <iostream>
#include <ctime>

using namespace std;

int main() {
    time_t t;
    t = time(NULL);
    cout << t << endl;
    return 0;
}