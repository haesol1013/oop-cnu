#include <iostream>
#include <string>
using namespace std;

class Animal {
    string name;

public:
    Animal() = default;

    explicit Animal(string name) : name(name) {
    };

    void showName() {
        cout << "Name is " << name << endl;
    }

    Animal& operator+(const Animal& a) {
        name += a.name;
        return *this;
    }
};

int main() {
    Animal cat("Nabi");
    cat.showName();
    Animal dog("Jindo");
    dog.showName();
    Animal catDog = dog + cat;
    catDog.showName();
    dog.showName();
    getchar();
    return 0;
}
