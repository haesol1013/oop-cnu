#include <iostream>

#define MAX_STACK_SIZE 1000

class Stack {
    int top;

public:
    int arr[MAX_STACK_SIZE];
    Stack() { top = -1; };
    bool push(int x);
    int pop();
};

bool Stack::push(int x) {
    if (top >= MAX_STACK_SIZE - 1) {
        std::cout << "ERROR: stack overflow." << std::endl;
        return false;
    } else {
        arr[++top] = x;
        std::cout << x << " is pushed" << std::endl;
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        std::cout << "ERROR: stack is empty" << std::endl;
        return 0;
    } else {
        int x = arr[top--];
        return x;
    }
}

int main() {
    class Stack s;
    s.push(7);
    s.push(88);
    s.push(999);

    std::cout << s.pop() << " is popped" << std::endl;
    std::cout << s.pop() << " is popped" << std::endl;
    std::cout << s.pop() << " is popped" << std::endl;

    system("pause");

    return 0;
}
