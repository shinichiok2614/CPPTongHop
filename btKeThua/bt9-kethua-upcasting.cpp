#include "iostream"

using namespace std;

class Human {
private:
    string name;
    int age;
    string sex;
public:
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

    void show() {
        cout << "Human.show" << endl;
    }
};

class Person : public Human {
private:
    string address;
    string phone;
public:
    Person() {}

    Person(const string &name, int age, const string &sex, const string &address, const string &phone) : Human(name,
                                                                                                               age,
                                                                                                               sex),
                                                                                                         address(address),

                                                                                                         phone(phone) {}

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

    void show() {
        cout << "Person.show" << endl;
    }
};

int main() {
//    cout<<"Human"<<endl;
//    Human human;
//    cout<<"name: ";
//    string name;
//    cin>>name;
//    cout<<"age: ";
//    int age;
//    cin>>age;
//    cout<<"sex: ";
//    string sex;
//    cin>>sex;
//    human.setName(name);
//    human.setAge(age);
//    human.setSex(sex);
//    human.getName();
//    human.getAge();
//    human.getSex();

    Person person("tuan", 20, "men", "236 hqv", "09123456");
    cout << person.getName() << endl;
    person.show();

//upcasting bằng tham chiếu
    Human &human = person;
    human.show();

    cout << "*p: ";
    Human *p = new Person;
    p->show();

    cout << "ptrp: ";
    Human *ptrp = &person;
    ptrp->show();

    cout<<"ptrvoidp: ";
    void* ptrvoidp=&person;
    Human* ptrHuman=static_cast<Human*>(ptrvoidp);
    ptrHuman->show();

    cout<<"shared_ptr: ";
    shared_ptr<Human> ptrsharedp= make_shared<Person>("personshr",20,"men","236 hqv", "01234567");
    ptrsharedp->show();

    
}
