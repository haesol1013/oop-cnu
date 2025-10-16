#include <iostream>
using namespace std;

class GlobalLogger {
    int log_value;
public:
    explicit GlobalLogger(int v = 0) {
        log_value = v;
    }

    int get_log_data() const {
        return log_value;
    }

    void set_log_data(int v) {
        log_value = v;
    }
};

GlobalLogger *global_Logger_ptr = 0;

void Logger_User_A() {
    if (!global_Logger_ptr) {
        global_Logger_ptr = new GlobalLogger;
    }
    global_Logger_ptr->set_log_data(1);
    cout << "Logger_User_A: log_data is " << global_Logger_ptr->get_log_data() << endl;
}

void Logger_User_B() {
    if (!global_Logger_ptr) {
        global_Logger_ptr = new GlobalLogger;
    }
    global_Logger_ptr->set_log_data(2);
    cout << "Logger_User_B: log_data is " << global_Logger_ptr->get_log_data() << endl;
}

int main() {
    if (!global_Logger_ptr) {
        global_Logger_ptr = new GlobalLogger;
    }
    cout << "main: log_data is " << global_Logger_ptr->get_log_data() << endl;
    Logger_User_A();
    Logger_User_B();
}
