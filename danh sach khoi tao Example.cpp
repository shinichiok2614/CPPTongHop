#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(std::string name, int age) : name(name), age(age) {
        std::cout << "Person constructor called" << std::endl;
    }
};

class Student : public Person {
public:
    int studentId;

    Student(std::string name, int age, int studentId) : Person(name, age), studentId(studentId) {
        std::cout << "Student constructor called" << std::endl;
    }
};

int main() {
    Student s("Alice", 20, 12345);
    return 0;
}