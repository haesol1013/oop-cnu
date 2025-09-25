#include <iostream>
using namespace std;

class Test {
public:
    int num1, num2;

    Test(int num1, int num2) : num1(num1), num2(num2) {
    }

    void print() {
        cout << "num1 : " << num1 << endl;
        cout << "num2 : " << num2 << endl;
    }
};

int main() {
    Test a = Test(1, 3);
    a.print();

    return 0;
}
