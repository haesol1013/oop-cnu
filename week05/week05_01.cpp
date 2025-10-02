#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class My_cat {
    int age;
    char* name;
    int weight;
    static int number_of_cats;

public:
    My_cat();

    My_cat(int x, const char* name);

    My_cat(const My_cat& cat);

    ~My_cat();

    void show_status() const;
};

My_cat::My_cat() : age(20), name(NULL), weight(10) {
    number_of_cats++;
}

My_cat::My_cat(int x, const char* cat_name) : weight(10) {
    age = x;
    name = new char[strlen(cat_name) + 1];
    strcpy(name, cat_name);
    number_of_cats++;
}

My_cat::My_cat(const My_cat& cat) : weight(10) {
    // Copy constructor
    cout << "Copy constructor invocation ! " << endl;
    age = cat.age;
    name = new char[strlen(cat.name) + 1];
    strcpy(name, cat.name);
    number_of_cats++;
}

My_cat::~My_cat() {
    // Destructor
    if (name) delete[] name;
    number_of_cats--;
}

void My_cat::show_status() const {
    cout << "My Cat Name :: " << name << endl;
    cout << " Age : " << age << endl;
    cout << " Weight : " << weight << endl;
    cout << " Current Number of Cats : " << number_of_cats << endl;
}

int My_cat::number_of_cats = 0;

int main() {
    My_cat cat1(3, "Nabi"); //Cat 1 생성
    cat1.show_status();

    My_cat cat2 = cat1; //Cat 2 복사 생성
    cat2.show_status();

    My_cat cat3(4, "ToTo"); //Cat 3 생성
    cat3.show_status();

    getchar();

    return 0;
}
