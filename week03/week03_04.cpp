#include <iostream>
using namespace std;

int& func(int& a) {
    return a;
}

int main() {
    int x = 1;
    cout << func(x)++ << endl;
    cout << x << endl;
}
