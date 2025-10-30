#include <iostream>

class SetValue {
    int x, y;

public:
    void setXY(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void show() {
        std::cout << "X = " << this->x << " , Y = " << this->y << std::endl;
    }

};

int main() {
    SetValue obj;

    obj.setXY(33, 44);
    obj.show();

    system("pause");
    return 0;
}