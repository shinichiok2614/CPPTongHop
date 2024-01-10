#include "arrSort.h"
#include <iostream>
using namespace std;
class Bag {
private:
	int gt;
	int tl;
	double donvi;
public:
	void setgt(int);
	int getgt();
	void settl(int);
	int gettl();
	double getdonvi();
};
void Bag::setgt(int a) {
	this->gt = a;
}
int Bag::getgt() {
	return this->gt;
}
void Bag::settl(int a) {
	this->tl = a;
}
int Bag::gettl() {
	return this->tl;
}
double Bag::getdonvi() {
	this->donvi =(double) this->getgt() / this->gettl();
	return this->donvi;
}
int main() {
	const int ds1size = 4;
	Bag* ds1 = new Bag[ds1size];

	ds1[0].setgt(1);	ds1[0].settl(3);
	ds1[1].setgt(5);	ds1[1].settl(2);
	ds1[2].setgt(6);	ds1[2].settl(9);
	ds1[3].setgt(2);	ds1[3].settl(4);
	double gt1[ds1size];
	for (int i = 0; i < ds1size; i++) {
		gt1[i] = ds1[i].getdonvi();
	}
	arrSort gt;
	gt.set(gt1, ds1size);
	double* gt2;
	gt2 = gt.mergeSort();
	for (int i = 0; i < ds1size; i++) {
		for (int j = 0; j < ds1size; j++) {
			if (gt2[i] == gt1[j]) cout << gt1[j] << " " << ds1[j].getgt() << " " << ds1[j].gettl() << endl;
		}
	}
	
	return 1;
}