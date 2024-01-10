#include <iostream>
using namespace std;

class Human {
public:
    string name;
    int age;
    string sex;

    Human(string n, int a, string s) {
        name = n;
        age = a;
        sex = s;
    }
    
    Human();

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getSex() {
        return sex;
    }
    void show();
};

class Person : public Human {
private:
    string address;
    string phone;

public:
    Person(string n, int a, string s, string addr, string ph) : Human(n, a, s) {
        address = addr;
        phone = ph;
    }

    Person();

    string getAddress() {
        return address;
    }

    string getPhone() {
        return phone;
    }
    void show();
};

class Worker : public Human {
private:
    int hour;
    double salary;
public:
    // Constructors
    Worker() : Human(), hour(0), salary(0.0) {}
    Worker(string name, int age, string sex, int hour, double salary) : Human(name, age, sex), hour(hour), salary(salary) {}

    // Accessor methods
    int getHour() const { return hour; }
    double getSalary() const { return salary; }

    // Mutator methods
    void setHour(int hour) { this->hour = hour; }
    void setSalary(double salary) { this->salary = salary; }
};
class Employee : public Person, public Worker {
private:
    string position;
public:
    // Constructors
    Employee() : Person(), Worker(), position("") {}
    Employee(string name, int age, string sex, string address, string phone, int hour, double salary, string position)
        : Person(name, age, sex, address, phone), Worker(name, age, sex, hour, salary), position(position) {}

    // Accessor methods
    string getPosition() const { return position; }

    // Mutator methods
    void setPosition(string position) { this->position = position; }
};

