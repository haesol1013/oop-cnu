#include <iostream>
using namespace std;

class IStrategy {
public:
    virtual ~IStrategy() = default;
    virtual int doOperation(int num1, int num2) const = 0;
};

class OperationAdd : public IStrategy {
public:
    int doOperation(int num1, int num2) const override {
        return num1 + num2;
    }
};

class OperationSubtract : public IStrategy {
public:
    int doOperation(int num1, int num2) const override {
        return num1 - num2;
    }
};

class OperationMultiply : public IStrategy {
public:
    int doOperation(int num1, int num2) const override {
        return num1 * num2;
    }
};

class Context {
    IStrategy* strategy;
public:
    explicit Context(IStrategy* strategy) : strategy(strategy) {}

    int executeStrategy(int num1, int num2) const {
        return strategy->doOperation(num1, num2);
    }
};

int main() {
    Context* context = new Context(new OperationAdd());
    cout << "10 + 5 = " << context->executeStrategy(10, 5) << endl;
    delete context;

    context = new Context(new OperationSubtract());
    cout << "10 - 5 = " << context->executeStrategy(10, 5) << endl;
    delete context;

    context = new Context(new OperationMultiply());
    cout << "10 * 5 = " << context->executeStrategy(10, 5) << endl;
    delete context;

    return 0;
}
