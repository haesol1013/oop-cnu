#include <iostream>

template<typename T>
void swap(T& a, T& b) {
    T tmep = a;
    a = b;
    b = tmep;
}

int main() {
    int a = 1;
    int b = 2;
    float c = 3.3f;
    float d = 4.4f;

    swap(a, b);
    swap(c, d);

    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "c: " << c << ", d: " << d << std::endl;
}
