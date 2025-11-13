#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Rect {
    int w, h;

public:
    Rect() : w(0), h(0) {}
    Rect(const int w, const int h) : w(w), h(h) {}

    int area() const {
        return w * h;
    }

    void print() const {
        cout << "(" << w << ", " << h << ", " << area() << ")" << endl;
    }
};

bool compareRects(const Rect& a, const Rect& b) {
    return a.area() < b.area();
}

int main() {
    int count;
    cout << "number of rect: ";
    cin >> count;

    vector<Rect> rects;
    int width, height;

    for (int i = 0; i < count; ++i) {
        cout << "width of rect: ";
        cin >> width;

        cout << "height of rect: ";
        cin >> height;

        rects.emplace_back(width, height);
    }

    sort(rects.begin(), rects.end(), compareRects);

    cout << "\n --- result --- " << endl;
    for (const Rect& rect : rects) {
        rect.print();
    }
    return 0;
}