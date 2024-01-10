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

    void fuctionHuman() {
        cout << "fuctionHuman" << endl;
    };

    virtual ~Human() {}
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

    void fuctionPerson() {
        cout << "fuctionPerson" << endl;
    }
};

int main() {

    Person person("tuan", 20, "men", "236 hqv", "09123456");
    cout << person.getName() << endl;
    person.show();

    //upcasting - con dùng được hàm của cha
    Human &human = person;
    human.show();

    cout << "*p: ";
    Human *p = new Person;
    p->show();

    cout << "ptrp: ";
    Human *ptrp = &person;       //<-downcasting bắt đầu từ đây, tạo con trỏ lớp cha tham chiếu tới lớp con
    ptrp->show();

    cout << "ptrvoidp: ";
    void *ptrvoidp = &person;
    Human *ptrHuman = static_cast<Human *>(ptrvoidp);
    ptrHuman->show();

    cout << "shared_ptr: ";
    shared_ptr<Human> ptrsharedp = make_shared<Person>("personshr", 20, "men", "236 hqv", "01234567");
    ptrsharedp->show();

    //downcasting - cha dùng được hàm của con
    cout << "Person *: ";
    Person *per = (Person *) new Human;
    per->fuctionPerson();

    Human human2("human", 21, "men");
    //Person &persondown=human2;
    //Person* ptrh=&human2;
    cout << "dynamic_cast: ";
    Person *ptrperson = dynamic_cast<Person *>(ptrp);  //phải có hàm ảo, là chữ ký xđ kiểu thực sự lúc khởi chạy
    ptrperson->fuctionPerson();
}
