#include <iostream>

template <typename T>
void fun(const T& x) {
    static int count = 0;
    std::cout << "x = " << x << " count = " << count << std::endl;
    ++count;
}

int main() {
    fun(1);
    std::cout << std::endl;
    fun(1);
    std::cout << std::endl;
    fun(1.1);
    std::cout << std::endl;
    return 0;
}
