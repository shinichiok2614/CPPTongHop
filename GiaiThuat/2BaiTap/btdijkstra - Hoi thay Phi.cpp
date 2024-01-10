#include <iostream>
using namespace std;
class SomeThing {
private:
	int gt;
	int tl;
public:
	SomeThing(int, int);
	void setgt(int);
	int getgt();
	void settl(int);
	int gettl();
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
int main() {
	cout << "hlw";
	SomeThing* dsST{};
	//lam sao de khai bao tung phan tu
	//dsST[0](1, 3);
	dsST[0] = SomeThing(1, 3);
	dsST[1] = SomeThing(5, 2);
	dsST[2] = SomeThing( 6,9 );
	dsST[3] = SomeThing( 2,4 );
	/*dsST[0].setgt(1);	dsST[0].settl(3);
	dsST[1].setgt(5);	dsST[1].settl(2);
	dsST[2].setgt(6);	dsST[2].settl(9);
	dsST[3].setgt(2);	dsST[3].settl(4);*/
	for (int i = 0; i < 3; i++) {
		cout << dsST[i].getgt() << " " << dsST[i].gettl() << endl;
	}
	return 1;
}