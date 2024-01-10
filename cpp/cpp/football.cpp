
#include <iostream>
#include <Player.h>
using namespace std;
int main()
{
    Player p1;
	string name;
	int number;
	double ability;
	double age;
	bool isforeign;
	int hs;
    std::cout << "Hello World!\n";
    cout << "nhap thong tin cau thu 1" << endl;
	cout << "ten: "; cin >> name; cout << endl;
	p1.setname(name);
	cout << p1.getname() << endl;
}

