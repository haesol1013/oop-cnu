#include <iostream>
using namespace std;

int main() {
    int num = 10;

    cout << "Address of int num: " << &num << endl;
    cout << "Value of int num: " << num << endl << endl;

    int& ref = num;

    cout << "Address of int& ref: " << &ref << endl;
    cout << "Value of int& ref: " << ref << endl << endl;

    int* ptr = &num;
    cout << "Address of int* ptr: " << &ptr << endl;
    cout << "Value pointed to by int* ptr: " << *ptr << endl << endl;

    return 0;
}
