#include <iostream>
using namespace std;

int find_min(int (&arr)[5]) {
    int min = arr[0];
    for (int i = 1; i < 5; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[5] = {8, 1, 7, 3, 5};
    int (&ref)[5] = arr;

    cout << "Minimum Value: " << find_min(ref) << endl;

    return 0;
}
