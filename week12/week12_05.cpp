#include <iostream>

using namespace std;

class Student {
    string rollNo;
    string name;

public:
    string& getRollNo() {
        return rollNo;
    }

    void setRollNo(const string& rollNo) {
        this->rollNo = rollNo;
    }

    string& getName() {
        return name;
    }

    void setName(const string& name) {
        this->name = name;
    }
};

class StudentView {
public:
    void printStudentDetails(string& studentName, string& studentRollNo) {
        cout << "Student: " << endl;
        cout << "Name: " << studentName << endl;
        cout << "Roll No: " << studentRollNo << endl;
    }
};

class StudentController {
    Student& model;
    StudentView& view;

public:
    StudentController(Student& model, StudentView& view)
        : model(model), view(view) {}

    void setStudentName(const string& name) {
        model.setName(name);
    }

    string& getStudentName() {
        return model.getName();
    }

    void setStudentRollNo(const string& rollNo) {
        model.setRollNo(rollNo);
    }

    string& getStudentRollNo() {
        return model.getRollNo();
    }

    void updateView() {
        view.printStudentDetails(model.getName(), model.getRollNo());
    }
};

Student retrieveStudentFromDatabase() {
    Student student;
    student.setName("Robert");
    student.setRollNo("10");
    return student;
}

void MVCPatternDemo() {
    Student model = retrieveStudentFromDatabase();

    StudentView view;

    StudentController controller(model, view);

    controller.updateView();

    controller.setStudentName("John");

    controller.updateView();
}
int main() {
    MVCPatternDemo();
}
