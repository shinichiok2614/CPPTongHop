#include "iostream"

using namespace std;
class Human{
public:
    string name;
    int age;
    string sex;

    Human() {}

    Human(const string &name, int age, const string &sex) : name(name), age(age), sex(sex) {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Human::name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Human::age = age;
    }

    const string &getSex() const {
        return sex;
    }

    void setSex(const string &sex) {
        Human::sex = sex;
    }

};
class Person: public Human{
private:
    string address;
    string phone;
public:
    Person() {}

    Person(const string &name, int age, const string &sex) : Human(name, age, sex) {}

    const string &getAddress() const {
        return address;
    }

    void setAddress(const string &address) {
        Person::address = address;
    }

    const string &getPhone() const {
        return phone;
    }

    void setPhone(const string &phone) {
        Person::phone = phone;
    }
};
class Worker: public Human{
private:
    int hour;
    double salary;
public:
    Worker() {}

    Worker(const string &name, int age, const string &sex) : Human(name, age, sex) {}

    int getHour() const {
        return hour;
    }

    void setHour(int hour) {
        Worker::hour = hour;
    }

    double getSalary() const {
        return salary;
    }

    void setSalary(double salary) {
        Worker::salary = salary;
    }
};
class Employee: public Person, public Worker{
private:
    string position;
public:
    Employee() {}

    Employee(const string &name, int age, const string &sex, const string &name1, int age1, const string &sex1)
            : Person(name, age, sex), Worker(name1, age1, sex1) {}

    const string &getPosition() const {
        return position;
    }

    void setPosition(const string &position) {
        Employee::position = position;
    }
};