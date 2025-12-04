#include <iostream>

class RideStrategy {
public:
    virtual ~RideStrategy() = default;

    virtual void ride() = 0;
};

class Bus : public RideStrategy {
public:
    void ride() override {
        std::cout << "Ride bus!" << std::endl;
    }
};

class Taxi : public RideStrategy {
public:
    void ride() override {
        std::cout << "Ride Taxi!" << std::endl;
    }
};

class Person {
public:
    explicit Person(RideStrategy* ride) {
        rideStrategy = ride;
    }

    virtual ~Person() = default;

    void run() {
        std::cout << "I run!" << std::endl;
    }

    void walk() {
        std::cout << "I walk!" << std::endl;
    }

    virtual void ride() {
        rideStrategy->ride();
    }

    void setRideStratage(RideStrategy* ride) {
        rideStrategy = ride;
    }

protected:
    RideStrategy* rideStrategy;
};

class James : public Person {
public:
    explicit James(RideStrategy* ride) : Person(ride) {};

    void ride() override {
        std::cout << "James: " << std::endl;
        rideStrategy->ride();
    }
};

int main() {
    RideStrategy* rideBus = new Bus;
    RideStrategy* rideTaxi = new Taxi;
    Person* james = new James(rideBus);
    james->run();
    james->walk();
    james->ride();
    james->setRideStratage(rideTaxi);
    james->ride();
    delete james;
    return 0;
}
