#include <iostream>
#include <string>

using namespace std;

class Human {
protected:
    string name;
    int age;
    char sex;
public:
    Human() {}
    Human(string name, int age, char sex) : name(name), age(age), sex(sex) {}
    virtual void show() = 0;
};

class Person : virtual public Human {
protected:
    string address;
    string phone_number;
public:
    Person() {}
    Person(string name, int age, char sex, string address, string phone_number)
        : Human(name, age, sex), address(address), phone_number(phone_number) {}
    virtual void show() = 0;
};

class Worker : virtual public Human {
protected:
    int hour;
    float salary;
public:
    Worker() {}
    Worker(string name, int age, char sex, int hour, float salary)
        : Human(name, age, sex), hour(hour), salary(salary) {}
    virtual void show() = 0;
};

class Employee : public Person, public Worker {
protected:
    string position;
public:
    Employee() {}
    Employee(string name, int age, char sex, string address, string phone_number,
        int hour, float salary, string position)
        : Person(name, age, sex, address, phone_number), Worker(name, age, sex, hour, salary),
        position(position) {}
    virtual void show() {
        cout << "Employee: " << endl;
        cout << "- Name: " << name << endl;
        cout << "- Age: " << age << endl;
        cout << "- Sex: " << sex << endl;
        cout << "- Address: " << address << endl;
        cout << "- Phone number: " << phone_number << endl;
        cout << "- Hour: " << hour << endl;
        cout << "- Salary: " << salary << endl;
        cout << "- Position: " << position << endl;
    }
};

int main() {
    Human* h;

    h = new Human("John Doe", 30, "M");
    h->show();
    delete h;

    h = new Person("Jane Doe", 25, "f", "123 Main St", "555-1234");
    h->show();
    delete h;

    h = new Worker("Bob Smith", 35, "m", 160, 4000.0);
    h->show();
    delete h;

    h = new Employee("Mary Johnson", 28, 'F', "456 Oak St", "555-5678", 180, 5000.0, "Manager");
    h->show();
    delete h;

    return 0;
}
