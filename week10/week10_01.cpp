#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Shape;
class AbstractFactory;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class RoundedRectangle : public Shape {
public:
    void draw() override {
        cout << "Inside RoundedRectangle::draw() method." << endl;
    }
};

class RoundedSquare : public Shape {
public:
    void draw() override {
        cout << "Inside RoundedSquare::draw() method." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Inside Rectangle::draw() method." << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Inside Square::draw() method." << endl;
    }
};

class AbstractFactory {
public:
    virtual unique_ptr<Shape> getShape(const string& shapeType) = 0;
    virtual ~AbstractFactory() = default;
};

class ShapeFactory : public AbstractFactory {
public:
    unique_ptr<Shape> getShape(const string &shapeType) override {
        if (shapeType == "RECTANGLE") {
            return make_unique<Rectangle>();
        }
        if (shapeType == "SQUARE") {
            return make_unique<Square>();
        }
        return nullptr;
    }
};

class RoundedShapeFactory : public AbstractFactory {
public:
    unique_ptr<Shape> getShape(const string &shapeType) override {
        if (shapeType == "RECTANGLE") {
            return make_unique<RoundedRectangle>();
        }
        if (shapeType == "SQUARE") {
            return make_unique<RoundedSquare>();
        }
        return nullptr;
    }
};

class FactoryProducer {
public:
    static unique_ptr<AbstractFactory> getFactory(bool rounded) {
        if (rounded) {
            return make_unique<RoundedShapeFactory>();
        } else {
            return make_unique<ShapeFactory>();
        }
    }
};

void AbstractFactoryPatternDemo() {
    unique_ptr<AbstractFactory> shapeFactory = FactoryProducer::getFactory(false);

    unique_ptr<Shape> shape1 = shapeFactory->getShape("RECTANGLE");
    shape1->draw();

    unique_ptr<Shape> shape2 = shapeFactory->getShape("SQUARE");
    shape2->draw();

    unique_ptr<AbstractFactory> shapedFactory1 = FactoryProducer::getFactory(true);

    unique_ptr<Shape> shape3 = shapedFactory1->getShape("RECTANGLE");
    shape3->draw();

    unique_ptr<Shape> shape4 = shapedFactory1->getShape("SQUARE");
    shape4->draw();
}

int main() {
    AbstractFactoryPatternDemo();
    return 0;
}