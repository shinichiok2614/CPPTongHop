#include<iostream>
using namespace std;
class Subsequences {
private:
	double* a;
	int asize;
	int start;
	int end;
public:
	Subsequences(double[], int);
	void search();
	int getStart();
	int getEnd();
};
Subsequences::Subsequences(double a[], int asize) {
	//for (int i = 0; i < asize; i++) {
	//	this->a = b;
	//}
	this->a = a;
	this->asize = asize;
	this->start = 0;
	this->end = 0;
}
int Subsequences::getStart() {
	return this->start;
}
int Subsequences::getEnd() {
	return this->end;
}
void Subsequences::search() {
	double maxE = a[0], maxS = a[0];
	int s1 = 0; start = 0, end = 0;
	for (int i = 1; i < asize; i++) {
		if (a[i] + maxE > a[i]) {
			maxE = a[i] + maxE;
		}
		else {
			maxE = a[i];
			s1 = i;
		}
		if (maxE > maxS) {
			maxS = maxE;
			start = s1;
			end = i;
		}
		cout << i << " " << a[i] << " " << maxE << " " << s1 << " " << maxS << " " << start << " " << end << "\n";
	}
}
int main() {
	double a[] = { 13,-15,2,18,4,8,0,-5,-8 };
	int asize = sizeof(a) / sizeof(a[0]);
	Subsequences sub(a, asize);
	sub.search();
	for (int i = sub.getStart(); i <= sub.getEnd(); i++)
		cout << a[i] << " ";
	return 1;
}