#include <iostream>
using namespace std;

class Circle {
    const double PI = 3.14;
    double radius; // 반지름
    double cir, area; // 둘레, 면적
    static int count; // 정적 변수

public:
    Circle() : radius(0.0), cir(0.0), area(0.0) {
        count++;
    }

    explicit Circle(double r) {
        this->radius = r;
        this->cir = 2 * PI * radius;
        this->area = PI * radius * radius;
        count++;
    }

    void printCircle() const {
        cout << "Radius of Circle : " << radius << endl;
        cout << "Circumference of Circle : " << cir << endl;
        cout << "Area of Circle : " << area << endl;
        cout << "The number of Circles : " << count << endl;
    }
};

int Circle::count = 0;

int main() {
    Circle c1;
    c1.printCircle();

    Circle c2(3);
    c2.printCircle();

    Circle c3(5.5);
    c3.printCircle();

    return 0;
}
