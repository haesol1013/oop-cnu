#include <iostream>
using namespace std;

class Mydata {
    int number;
    string strNumber;

public:
    Mydata(const int data, const string &str) : number(data), strNumber(str) {}

    operator int() const {
        return number;
    }

    operator string() {
        return strNumber;
    }

    int operator++() {
        return ++number;
    }

    int operator++(int) {
        const int temp = number;
        number++;
        return temp;
    }

    friend ostream& operator<<(ostream&, Mydata&);
};

ostream& operator<<(ostream& os, Mydata& md) {
    return os << "This number is: " << md.strNumber << "\n";
}

int main() {
    Mydata mydata(1, "one");
    string strNum = mydata;
    int intNum = mydata;
    cout << strNum << endl;
    cout << intNum << endl;
    cout << mydata++ << endl;
    cout << ++mydata << endl;
    cout << mydata;
}
