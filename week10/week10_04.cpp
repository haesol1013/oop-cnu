#include <iostream>
#include <cassert>

class CEO {
public:
    virtual ~CEO() = default;
};

class CPO {
public:
    virtual ~CPO() = default;
};

class Manager : public CEO, public CPO {
public:
    virtual ~Manager() = default;
};

class Staff : public Manager {
public:
    ~Staff() override = default;
};

int main() {
    CPO* cpo = new Staff();
    Staff* staff = dynamic_cast<Staff*>(cpo);
    Manager* manager = dynamic_cast<Manager*>(staff);
    CEO* ceo = dynamic_cast<CEO*>(cpo);
    assert(typeid(cpo) == typeid(Staff*));
}
