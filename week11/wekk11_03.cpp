#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Observer;
class Subject; 

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
    Subject* subject;

public:
    virtual void update() = 0;
    virtual ~Observer() = default; 
};

void Subject::notifyAllObservers() const {
    for (Observer* observer : observers) {
        observer->update();
    }
}

class BinaryObserver : public Observer {
public:
    explicit BinaryObserver(Subject* subject) {
        this->subject = subject;
        this->subject->attach(this);
    }

    void update() override {
        string binaryString;
        int n = subject->getState();
        if (n == 0) binaryString = "0";
        while (n > 0) {
            binaryString = ( (n % 2) == 0 ? "0" : "1" ) + binaryString;
            n /= 2;
        }
        cout << "Binary String: " << binaryString << endl; 
    }
};

class OctalObserver : public Observer {
public:
    explicit OctalObserver(Subject* subject) {
        this->subject = subject;
        this->subject->attach(this);
    }

    void update() override {
        cout << "Octal String: " << oct << subject->getState() << dec << endl;
    }
};

class HexaObserver : public Observer {
public:
    explicit HexaObserver(Subject* subject) {
        this->subject = subject;
        this->subject->attach(this);
    }

    void update() override {
        cout << "Hex String: " << uppercase << hex << subject->getState() << dec << endl;
    }
};

void ObserverPatternDemo() {
    Subject subject;

    HexaObserver hObs(&subject);
    OctalObserver oObs(&subject);
    BinaryObserver bObs(&subject);

    cout << "First state change: 15" << endl;
    subject.setState(15);

    cout << "Second state change: 10" << endl;
    subject.setState(10);
}

int main() {
    ObserverPatternDemo();
    return 0;
}
