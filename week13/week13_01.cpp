#include <iostream>

template <typename T = double>
T sum() {
    return T{0};
}

template <typename T, typename... Args>
auto sum(T first, Args... args) {
    return first + sum(args...);
}

template <typename... Args>
auto average(Args... args) {
    auto total_sum = sum(args...);
    auto count = static_cast<double>(sizeof...(args));
    return total_sum / count;
}

int main() {
    std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;
}
