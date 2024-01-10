#include <iostream>

using namespace std;

class Human {
protected:
    string name;
    int age;
    string sex;
public:
    Human();
    Human(string name, int age, string sex) {
        this->name = name;
        this->age = age;
        this->sex = sex;
    }
    virtual void show() = 0; // phương thức thuần ảo
    void setName(string name);
    void setAge(int age);
    void setSex(string sex);
};

class Person : public virtual Human {
protected:
    string address;
    string phone;
public:
    Person() {};
    Person(string name, int age, string sex, string address, string phone) : Human(name, age, sex){
        /*this->name = name;
        this->age = age;
        this->sex = sex;*/
        this->address = address;
        this->phone = phone;
    }
    void show() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Worker : public virtual Human {
protected:
    int hour;
    double salary;
public:
    Worker() {};
    Worker(string name, int age, string sex, int hour, double salary) : Human(name, age, sex) {
        /*this->name = name;
        this->age = age;
        this->sex = sex;*/
        this->hour = hour;
        this->salary = salary;
    }
    void show() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Working hours: " << hour << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Employee : public Person, public Worker {
protected:
    string position;
public:
    Employee() {};
    Employee(string name, int age, string sex, string address, string phone, int hour, double salary, string position) :
        Person(name, age, sex, address, phone), Worker(name, age, sex, hour, salary) {
        Human::setName(name);
        Human::setAge(age);
        Human::setSex(sex);
        this->position = position;
    }
    void show() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Working hours: " << hour << endl;
        cout << "Salary: " << salary << endl;
        cout << "Position: " << position << endl;
    }
};
int main() {
    Employee emp("John Doe", 30, "nam", "123 Main St", "555-1234", 160, 2000, "Manager");
    Employee e1("Nguyen Van A", 18, "nu", "HaNoi", "113", 8, 2000, "NhanVien");
    


    emp.Employee::show();
    emp.Person::show();
    emp.Worker::show();
    return 1;
}

