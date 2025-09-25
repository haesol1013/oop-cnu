#include <iostream>
#include <cstring>
using namespace std;

class Animal {
public:
    char* name;
    int age;

    Animal(int age_, const char* name_) {
        age = age_;
        name = new char[strlen(name_)+1];
        strcpy(name, name_);
    }

    Animal(const Animal& a) {
        age = a.age;
        name = a.name;
    }

    void changeName(const char* newName) {
        strcpy(name, newName);
    }

    void printAnimal() {
        cout << "Name: " << name << " Age: " << age << endl;
    }
};

int main() {
    Animal A(10, "Jenny");
    Animal B = A;
    A.age = 22;
    A.changeName("Brown");

    A.printAnimal();
    B.printAnimal();

    return 0;
}