#include <iostream>
using namespace std;

class Obj {
    int val;

public:
    Obj() : val(5) {};

    void showValue() const {
        cout << val << endl;
    }

    Obj& operator++() {
        val++;
        return *this;
    }

    Obj operator++(int) {
        Obj const temp = *this;
        val++;
        return temp;
    }
};

int main() {
    Obj obj;
    obj.showValue();

    obj++;
    obj.showValue();

    ++obj;
    obj.showValue();
}