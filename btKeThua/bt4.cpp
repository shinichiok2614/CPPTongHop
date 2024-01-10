#include "iostream"

using namespace std;

class Human {
public:
    string name;
    int age;
    char sex;

    Human() {}

    Human(const string &name, int age, char sex) : name(name), age(age), sex(sex) {}
};

class Person : public Human {
private:
    string address;
    string phone;
public:
    Person() {}

    Person(const string &name, int age, char sex) : Human(name, age, sex) {}

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

int main() {
    Human human;
    cout<<"Ho va ten: ";
    cin>>human.name;
    cout<<human.name<<endl;
    Person person;
    cout << "person.address: ";
    string addr;
    cin>>addr;
    person.setAddress(addr);
    cout<<person.getAddress()<<endl;



}