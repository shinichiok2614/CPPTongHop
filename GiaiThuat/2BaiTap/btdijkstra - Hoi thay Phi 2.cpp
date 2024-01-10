#include <iostream>
using namespace std;
class SomeThing {
private:
	int gt;
	int tl;
	double donvi;
public:
	SomeThing(int, int);
	void setgt(int);
	int getgt();
	void settl(int);
	int gettl();
	double getdonvi();
};
SomeThing::SomeThing(int a, int b) {
	this->gt = a;
	this->tl = b;
}
void SomeThing::setgt(int a) {
	this->gt = a;
}
int SomeThing::getgt() {
	return this->gt;
}
void SomeThing::settl(int a) {
	this->tl = a;
}
int SomeThing::gettl() {
	return this->tl;
}
double SomeThing::getdonvi() {
	this->donvi = this->getgt() / this->gettl();
	return this->donvi;
}
int main() {
	//cout << "hlw";
	//SomeThing* dsST = new SomeThing(1,3);
	//cout << dsST->getgt() << " " << dsST->gettl();
	//SomeThing* dsST = new SomeThing[2];
	cout << SomeThing(6, 2).getdonvi();
	SomeThing a(4, 1);
	cout << a.getdonvi();
	/*dsST[0].setgt(1);	dsST[0].settl(3);
	dsST[1].setgt(5);	dsST[1].settl(2);
	dsST[2].setgt(6);	dsST[2].settl(9);
	dsST[3].setgt(2);	dsST[3].settl(4);*/
	/*for (int i = 0; i < 3; i++) {
		cout << dsST[i].getgt() << " " << dsST[i].gettl() << endl;
	}
	return 1;*/
}