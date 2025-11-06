#include <iostream>
#include <memory>
using namespace std;

class DrawAPI {
public:
    virtual void drawCircle(int radius, int x, int y) = 0;
    virtual ~DrawAPI() = default;
};

class RedCircle : public DrawAPI {
public:
    void drawCircle(int radius, int x, int y) override {
        cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", y: " << y << "]" << endl;
    }
};

class GreenCircle : public DrawAPI {
public:
    void drawCircle(int radius, int x, int y) override {
        cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", y: " << y << "]" << endl;
    }
};

class Shape {
protected:
    unique_ptr<DrawAPI> drawAPI;
    explicit Shape(unique_ptr<DrawAPI> api) : drawAPI(move(api)) {}

public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    int x, y, radius;

public:
    Circle(int x, int y, int radius, unique_ptr<DrawAPI> api)
        : Shape(move(api)), x(x), y(y), radius(radius) {}

    void draw() override {
        drawAPI->drawCircle(radius, x, y);
    }
};

void BridgePatternDemo() {
    unique_ptr<Shape> redCircle = make_unique<Circle>(100, 100, 10, make_unique<RedCircle>());
    unique_ptr<Shape> greenCircle = make_unique<Circle>(100, 100, 10, make_unique<GreenCircle>());

    redCircle->draw();
    greenCircle->draw();
}

int main() {
    BridgePatternDemo();
    return 0;
}