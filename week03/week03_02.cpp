#include <iostream>
using namespace std;

void increment(int* x) {
    ++*x;
}

int main() {
    int x = 55;
    cout << "Before increment: " << x << endl;

    increment(&x);
    cout << "After increment: " << x << endl;

    system("pause");
    return 0;
}