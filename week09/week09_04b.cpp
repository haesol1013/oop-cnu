#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int age;

public:
    Employee(
        const std::string &name,
        int age
    ) : name(name),
        age(age)
    {}

    virtual ~Employee() = default;

    virtual void showInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Manager : public Employee {
    int managerBonus;

public:
    Manager(
        int managerBonus,
        const std::string &name,
        int age
    ) : Employee(name, age),
        managerBonus(managerBonus)
    {}

    ~Manager() override = default;

    void showInfo () override {
        std::cout << "Manager Name: " << name << ", Age: " << age << ", managerBonus: " << managerBonus << std::endl;
    }
};

class Intern : public Employee {
    std::string majorName;

public:
    Intern(
        const std::string &major,
        const std::string &name,
        int age
    ) : Employee(name, age),
        majorName(major)
    {}

    ~Intern() override = default;

    void showInfo() override {
        std::cout << "Intern Name: " << name << ", Age: " << age << ", Major: " << majorName << std::endl;
    }
};

class Janitor : public Employee {
    int salary;

public:
    Janitor(
        int salary,
        const std::string &name,
        int age
    ) : Employee(name, age),
        salary(salary)
    {}

    ~Janitor() override = default;

    void showInfo() override {
        std::cout << "Janitor Name: " << name << ", Age: " << age << ", Salary: " << salary << std::endl;
    }
};

int main() {
    Employee** employeeList = new Employee* [6];
    employeeList[0] = new Manager(200, "James", 33);
    employeeList[1] = new Manager(150, "Chulsoo", 50);
    employeeList[2] = new Intern("security", "Minsu", 24);
    employeeList[3] = new Intern("HCI", "Yong", 19);
    employeeList[4] = new Janitor(100, "Black", 90);
    employeeList[5] = new Janitor(200, "White", 100);

    for(int i = 0; i < 6; i++) {
        employeeList[i]->showInfo();
    }

    for(int i = 0; i < 6; i++) {
        delete employeeList[i];
    }
    delete[] employeeList;

    getchar();
    return 0;
}
