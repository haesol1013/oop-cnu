#include <iostream>
#include <vector>
#include <bitset>
using namespace std;


class Observer;

class Subject {
    vector<Observer*> observers;
    int state;

public:
    int getState() const {
        return state;
    }

    void setState(int state) {
        this->state = state;
        notifyAllObservers();
    }

    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void notifyAllObservers() const;
};

class Observer {
protected:
    Subject* subject = nullptr;

public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

void Subject::notifyAllObservers() const {
    for (Observer* observer : observers) {
        observer->update();
    }
}

class OctalObserver : public Observer {
public:
    explicit OctalObserver(Subject* subject) {
        this->subject = subject;
        this->subject->attach(this);
    }
    void update() override {
        cout << "Octal String: " << oct << subject->getState() << endl;
    }
};

class HexaObserver : public Observer {
public:
    explicit HexaObserver(Subject* subject) {
        this->subject = subject;
        this->subject->attach(this);
    }

    void update() override {
        cout << "Hex String: " << hex << subject->getState() << endl;
    }
};

class BinaryObserver : public Observer {
public:
    explicit BinaryObserver(Subject* subject) {
        this->subject = subject;
        this->subject->attach(this);
    }

    void update() override {
        cout << "Binary String: " << bitset<8>(subject->getState()) << endl;
    }
};

int main() {
    Subject* subject = new Subject();

    new HexaObserver(subject);
    new OctalObserver(subject);
    new BinaryObserver(subject);

    cout << "First state change: 15" << endl;
    subject->setState(15);
    cout << "Second state change: 10" << endl;
    subject->setState(10);

    delete subject;
    return 0;
}
