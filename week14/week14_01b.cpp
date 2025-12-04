#include <vector>
#include <iostream>

class Car {
public:
    static Car* produceCar(int choice);

    virtual ~Car() = default;

    virtual void echoName() = 0;
};

class Sonata : public Car {
public:
    void echoName() override {
        std::cout << "I'm Sonata!" << std::endl;
    }
};

class Malibu : public Car {
public:
    void echoName() override {
        std::cout << "I'm Malibu!" << std::endl;
    }
};

class Spark : public Car {
public:
    void echoName() override {
        std::cout << "I'm Spark!" << std::endl;
    }
};

Car* Car::produceCar(int choice) {
    switch (choice) {
        case 1:
            return new Sonata;
        case 2:
            return new Malibu;
        case 3:
            return new Spark;
        default:
            return nullptr;
    }
}

int main() {
    std::vector<Car*> carCollection;
    int choice;
    while (true) {
        std::cout << "Choice: (Sonata:1, Malibu:2, Sparck:3, Done:0): ";
        std::cin >> choice;
        if (choice == 0) {
            break;
        }
        carCollection.push_back(Car::produceCar(choice));
    }
    for (auto & i : carCollection) {
        i->echoName();
    }
    for (auto & i : carCollection) {
        delete i;
    }
    return 0;
}
