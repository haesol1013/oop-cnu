#include <iostream>
#include <algorithm>
#include <forward_list>

template <typename ForwardList, typename Compare>
void bubble_sort(ForwardList first, ForwardList last, Compare comp) {
    bool swapped;

    do {
        swapped = false;
        ForwardList current = first;
        ForwardList next = first;
        std::advance(next, 1);

        while (next != last) {
            if (comp(*current, *next)) {
                std::iter_swap(current, next);
                swapped = true;
            }
            current = next;
            std::advance(next, 1);
        }
    } while (swapped);
}

class compGreater {
public:
    bool operator() (int a, int b) const {
        return a > b;
    }
};

class compLess {
public:
    bool operator() (int a, int b) const {
        return a < b;
    }
};

void print_list(const std::forward_list<int>& list) {
    for (int val : list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::forward_list<int> initial_values{ 7, 0, 6, 1, 5, 2, 4, 3 };

    std::forward_list<int> ascending = initial_values;
    bubble_sort(ascending.begin(), ascending.end(), compGreater());
    std::cout << "Ascending" << std::endl;
    print_list(ascending);

    std::forward_list<int> descending = initial_values;
    bubble_sort(descending.begin(), descending.end(), compLess());
    std::cout << "Descending" << std::endl;
    print_list(descending);

    return 0;
}
