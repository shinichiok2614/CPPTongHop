#include <iostream>
using namespace std;
class arrSort {
private:
	int* a;
	int size;
public:
	void set(int[], int);
	int* merge(int[], int, int[], int);
	int* mergeSort(int[], int);
	int* mergeSort();
};
void arrSort::set(int a[], int size) {
	this->a = a;
	this->size = size;
}
int* arrSort::merge(int c[], int sizec, int d[], int sized) {
	int* e = new int[100];
	int sizee = sizec + sized;
	int c1 = 0, d1 = 0, e1 = 0;
	while (e1 <= sizee) {
		if ((c1 < sizec) && (c[c1] <= d[d1])) {
			e[e1] = c[c1];
			c1++;
			e1++;
		}
		if (c1 == sizec) {
			e[e1] = d[d1];
			d1++;
			e1++;
		}
		if ((d1 < sized) && (d[d1] <= c[c1])) {
			e[e1] = d[d1];
			d1++;
			e1++;
		}
		if (d1 == sized) {
			e[e1] = c[c1];
			c1++;
			e1++;
		}
	}
	return e;
}
int* arrSort::mergeSort() {
	return this->mergeSort(this->a, this->size);
}
int* arrSort::mergeSort(int f[], int sizef) {
	int a = 0, c = sizef;
	int b = (a + c) / 2;
	if (sizef == 1) {
		int* f5 = new int[1];
		f5[0] = f[a];
		return f5;
	}
	else {
		int size1 = b - a;
		int size2 = c - b;
		int f1[100], f2[100];
		for (int i = 0; i < size1; i++) f1[i] = f[i];
		for (int i = 0; i < size2; i++) f2[i] = f[i + b];
		int* f3 = new int[100];
		f3 = this->mergeSort(f1, size1);
		int* f4 = new int[100];
		f4 = this->mergeSort(f2, size2);
		int* f5 = this->merge(f3, size1, f4, size2);
		return f5;
	}
}
int main() {
	arrSort a;
	int a2[] = { 12,5,7,5,4,2,1,6,9,8,7,12 };
	int sizea2 = sizeof(a2) / sizeof(a2[0]);
	a.set(a2, sizea2);
	int* output = a.mergeSort();
	for (int i = 0; i < sizea2; i++) {
		cout << output[i] << " ";
	}
	return 1;
}