#include <iostream>
using namespace std;

class A {
    int val;

public:
    explicit A(const int val) : val(val) {
        cout << "Constructor()" << endl;
    }

    ~A() {
        cout << "Deconstructor()" << endl;
    }

    int getValue() const {
        return val;
    }
};

int main() {
    try {
        A obj(10);
        throw obj;
    } catch (A& caught_obj) {
        cout << caught_obj.getValue() << endl;
    }
}
