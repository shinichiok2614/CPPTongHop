#include <iostream>

using namespace std;

class Human {
public:
    string name;
    int age;
    char sex;

    Human() {
        name = "";
        age = 0;
        sex = ' ';
    }

    // ham khoi tao 3 tham so
    Human(string n, int a, char s) {
        name = n;
        age = a;
        sex = s;
    }
};

class Person : public Human {
private:
    string address;
    string phone;

public:
     Person() : Human() {
        address = "";
        phone = "";
    }

    // ham khoi tao 5 tham so
    Person(string n, int a, char s, string addr, string ph) : Human(n, a, s) {
        address = addr;
        phone = ph;
    }
};
