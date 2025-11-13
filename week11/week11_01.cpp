#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers(10);

    for (int i = 0; i < 10; ++i) {
        cin >> numbers[i];
    }

    int max = *max_element(numbers.begin(), numbers.end());
    int min = *min_element(numbers.begin(), numbers.end());

    cout << "Max: " << max << ", Min: " << min << endl;
    return 0;
}
