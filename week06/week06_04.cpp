#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    int age;
    string address;

public:
    explicit Person(
        const string& name,
        const int age,
        const string& address
    ) : name(name),
        age(age),
        address(address)
    {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getAddress() const {
        return address;
    }
};

class Student : public Person{
    int student_id;

public:
    explicit Student(
        const string& name,
        const int age,
        const string& address
    ) : Person(name, age, address),
        student_id(0)
    {}

    void setStudentId(int student_id) {
        this->student_id = student_id;
    }

    int getStudentId() const {
        return student_id;
    }
};

int main() {
    Student a("Haesol", 21, "Daejeon");
    a.setStudentId(202401833);

    cout << "Student Information" << endl;
    cout << "Name : " << a.getName() << endl;
    cout << "Age : " << a.getAge() << endl;
    cout << "Address : " << a.getAddress() << endl;
    cout << "Student ID : " << a.getStudentId() << endl;
}
