class Animal {
public:
    Animal() {
        numberOfLeg = 0;
    }

    Animal(int numberOfLeg) {
        this->numberOfLeg = numberOfLeg;
    }

private:
    int numberOfLeg;
};

int main() {
    Animal a;
    return 0;
}
