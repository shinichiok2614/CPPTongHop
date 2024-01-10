#include <iostream>

using namespace std;

class Person : public Human {
private:
    string address;
    string phone;

public:
    Person(string n, int a, char s, string addr, string ph) : Human(n, a, s) {
        address = addr;
        phone = ph;
    }

    string getAddress() {
        return address;
    }

    string getPhone() {
        return phone;
    }

};
