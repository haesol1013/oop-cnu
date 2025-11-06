#include <iostream>
using namespace std;

class BaseClass {
public:
    virtual void display() = 0;
    ~BaseClass() = default;
};

class DerivedClass : public BaseClass {
public:
    void display() override {
        cout << "Everything is OKAY" << endl;
    }
};

int main() {
    BaseClass* obj = new DerivedClass();
    DerivedClass* derivedObj = dynamic_cast<DerivedClass*>(obj);
    if (derivedObj) {
        derivedObj->display();
    }
}