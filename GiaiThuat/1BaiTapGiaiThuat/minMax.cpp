#include <iostream>
using namespace std;
class MinMax {
private:
	int* a;
	int size;
	int min;
	int max;
	void set(int*, int, int, int);
	MinMax min1(int*, int);
	MinMax min2(int*, int, int,int, int*, int, int, int);
	MinMax max2(int*, int, int, int*, int, int);
public:
	void set(int*, int);
	void search();
	int* get();
	int getsize();
	int getmin();
	int getmax();
};
void MinMax::set(int a[], int size) {
	this->a = a;
	this->size = size;
}
void MinMax::set(int a[], int size, int min, int max) {
	this->a = a;
	this->size = size;
	this->min = min;
	this->max = max;
}
void MinMax::search() {
	MinMax m = min1(this->a, this->size);
	this->size = m.getsize();
	this->min = m.getmin();
	this->max = m.getmax();
}
int* MinMax::get() {
	return this->a;
}
int MinMax::getsize() {
	return this->size;
}
int MinMax::getmin() {
	return this->min;
}
int MinMax::getmax() {
	return this->max;
}
MinMax MinMax::min1(int a[], int size) {
	if (size == 1) {
		MinMax f5;
		f5.a = a;
		f5.size = size;
		f5.min = 0;
		f5.max = 0;
		return f5;
	}
	else {
		int f1[100], f2[100];
		int sizef1 = size / 2, sizef2 = size - sizef1;
		for (int i = 0; i < sizef1; i++) {
			f1[i] = a[i];
		}
		for (int i = 0; i < sizef2; i++) {
			f2[i] = a[i + sizef1];
		}
		MinMax f3, f4;
		f3.set(f1, sizef1, f3.min1(f1, sizef1).min, f3.min1(f1,sizef1).max);
		f4.set(f2, sizef2, f4.min1(f2, sizef2).min, f4.min1(f2, sizef2).max);
		return min2(f3.get(), f3.getsize(), f3.getmin(),f3.getmax(), f4.get(), f4.getsize(), f4.getmin(), f4.getmax());
	}
}
MinMax MinMax::min2(int f1[], int  sizef1, int minf1, int maxf1, int f2[], int sizef2, int minf2, int maxf2) {
	int min2min = (f1[minf1] <= f2[minf2]) ? minf1 : sizef1 + minf2;
	int min2max= (f1[maxf1] >= f2[maxf2]) ? maxf1 : sizef1 + maxf2;
	int min2f1[100];
	int sizemin2f1 = sizef1 + sizef2;
	for (int i = 0; i < sizef1; i++) {
		min2f1[i] = f1[i];
	}
	for (int i = 0; i < sizef2; i++) {
		min2f1[i + sizef1] = f2[i];
	}
	MinMax min2f2;
	min2f2.set(min2f1, sizemin2f1, min2min, min2max);
	return min2f2;
}
int main() {
	int a[] = { 5,3,5,6,8,6,331,2,23,6 };
	MinMax m;
	int sizea = sizeof(a) / sizeof(a[0]);
	m.set(a, sizea);
	m.search();
	cout << "phan tu nho nhat la: " << a[m.getmin()] << ", o vi tri: " << m.getmin() << endl;
	cout << "phan tu lon nhat la: " << a[m.getmax()] << ", o vi tri: " << m.getmax() << endl;
	return 1;
}