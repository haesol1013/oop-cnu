#include <iostream>
#include <execution>
using namespace std;

struct NewException final : exception {
    const char* what() const noexcept override {
        return "NewException";
    }
};

int main() {
    try {
        throw NewException();
    } catch (const exception& e) {
        cout << "My exception is " << e.what() << endl;
    }
}