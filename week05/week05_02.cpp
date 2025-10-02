#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class My_cat {
    char* name;
    int weight;

public:
    My_cat();

    explicit My_cat(const char* name);

    My_cat(const My_cat& cat);

    ~My_cat();

    My_cat& eat(int);

    My_cat& diet(int);

    void show_status() const;
};

My_cat::My_cat() : name(NULL), weight(10) {
}

My_cat::My_cat(const char* cat_name) : weight(10) {
    name = new char[strlen(cat_name) + 1];
    strcpy(name, cat_name);
}

My_cat::My_cat(const My_cat& cat) : weight(10) {
    // Copy constructor
    cout << "Copy constructor invocation ! " << endl;
    name = new char[strlen(cat.name) + 1];
    strcpy(name, cat.name);
}

My_cat::~My_cat() {
    // Destructor
    if (name) delete[] name;
}

My_cat& My_cat::eat(int n) {
    this->weight += n;
    return *this;
}

My_cat& My_cat::diet(int n) {
    if (this->weight - n >= 1) {
        this->weight -= n;
    }
    return *this;
}

void My_cat::show_status() const {
    cout << " Weight : " << weight << endl;
}

int main() {
    My_cat cat1("Nabi"); // Cat 1 생성
    cat1.show_status();

    cat1.eat(4);
    cat1.show_status();

    cat1.diet(1);
    cout << " and diet -> ";
    cat1.show_status();

    cat1.eat(4);
    cat1.show_status();

    cat1.diet(1);
    cout << " and diet -> ";
    cat1.show_status();

    cat1.eat(4).eat(5).eat(6);
    cat1.show_status();

    cat1.diet(1).diet(2);
    cout << " and diet -> ";
    cat1.show_status();

    getchar();

    return 0;
}
