#include <vector>
#include <iostream>

class Depositor {
public:
    virtual ~Depositor() = default;

    virtual void update(int money) = 0;
};

class Bank {
    int interest;
    std::vector<Depositor*> depositors;

public:
    void attach(Depositor* dps) {
        depositors.push_back(dps);
    }

    void addInterest(int interest) {
        this->interest = interest;
        notify();
    }

    void notify() const {
        for (auto& depositor : depositors)
            depositor->update(interest);
    }
};

class DepositorA : public Depositor {
    int deposit;

public:
    DepositorA(Bank* bank, int money) {
        bank->attach(this);
        deposit = money;
    }

    void update(int money) override {
        deposit += money;
        std::cout << " Depositor_A's balance is " << deposit << std::endl;
    }
};

class DepositorB : public Depositor {
    int deposit;

public:
    DepositorB(Bank *bank, int money) {
        bank->attach(this);
        deposit = money;
    }

    void update(int money) override {
        deposit += money;
        std::cout << " Depositor_B's balance is " << deposit << std::endl;
    }
};

int main() {
    Bank subj;
    DepositorA depA(&subj, 3000);
    DepositorB depB(&subj, 4000);
    subj.addInterest(10);
}
