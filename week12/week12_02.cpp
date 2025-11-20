#include <iostream>
#include <string>
#include <utility>

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<>
void swap(std::string& a, std::string& b) {
    std::string temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 1;
    int b = 2;
    float c = 3.3f;
    float d = 4.4f;
    std::string e = "World";
    std::string f = "Hello";

    swap(a, b);
    swap(c, d);
    swap(e, f);

    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "e: " << e << ", f: " << f << std::endl;
}
