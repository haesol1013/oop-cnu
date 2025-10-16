#include <iostream>
#include <string>
using namespace std;

class Employee {
    string emp_id;
    string name;
    int age;
    string address;
    float salary;

public:
    Employee(
        const string& emp_id,
        const string& name,
        const int age,
        const string& address,
        const float salary
    ) : emp_id(emp_id),
        name(name),
        age(age),
        address(address),
        salary(salary)
    {}

    string get_emp_id() const {
        return emp_id;
    }

    string get_name() const {
        return name;
    }

    int get_age() const {
        return age;
    }

    string get_address() const {
        return address;
    }

    float get_salary() const {
        return salary;
    }
};

class Manager : public Employee {
    int team_size;

public:
    Manager(
        const string& emp_id,
        const string& name,
        const int age,
        const string& address,
        const float salary,
        const int team_size
    ) : Employee(emp_id, name, age, address, salary),
        team_size(team_size)
    {}

    int get_team_size() const {
        return team_size;
    }
};

int main() {
    Manager manager{
        "EMP001",
        "Haesol",
        35,
        "seoul",
        5000.0f,
        10
    };

    cout << "Manager Information" << endl;
    cout << "Employee ID : " << manager.get_emp_id() << endl;
    cout << "Name : " << manager.get_name() << endl;
    cout << "Age : " << manager.get_age() << endl;
    cout << "Address : " << manager.get_address() << endl;
    cout << "Salary : $" << manager.get_salary() << endl;
    cout << "Team Size : " << manager.get_team_size() << endl;
}
