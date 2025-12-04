#include <iostream>
#include <memory>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Shape: Rectangle" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Shape: Circle" << endl;
    }
};

class ShapeDecorator : public Shape {
protected:
    std::unique_ptr<Shape> decoratedShape;

public:
    explicit ShapeDecorator(std::unique_ptr<Shape> decoratedShape)
        : decoratedShape(std::move(decoratedShape)) {}

    void draw() override {
        decoratedShape->draw();
    }
};

class RedShapeDecorator : public ShapeDecorator {
    void setRedBorder() {
        cout << "Border Color: Red" << endl;
    }

public:
    explicit RedShapeDecorator(std::unique_ptr<Shape> decoratedShape)
        : ShapeDecorator(std::move(decoratedShape)) {}

    void draw() override {
        decoratedShape->draw();
        setRedBorder();
    }
};

void DecoratorPatternDemo() {
    std::unique_ptr<Shape> circle = std::make_unique<Circle>();

    std::unique_ptr<Shape> redCircle = std::make_unique<RedShapeDecorator>(
        std::make_unique<Circle>()
    );

    std::unique_ptr<Shape> redRectangle = std::make_unique<RedShapeDecorator>(
        std::make_unique<Rectangle>()
    );

    cout << "Circle with normal border" << endl;
    circle->draw();

    cout << "\nCircle of red border" << endl;
    redCircle->draw();

    cout << "\nRectangle of red border" << endl;
    redRectangle->draw();
}

int main() {
    DecoratorPatternDemo();
    return 0;
}
