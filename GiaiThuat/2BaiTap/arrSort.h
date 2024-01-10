#pragma once
class arrSort
{
private:
	double* a;
	int size;
	double* merge(double[], int, double[], int);
	double* mergeSort(double[], int);
public:
	void set(double[], int);
	double* mergeSort();
};
void arrSort::set(double a[], int size) {
	this->a = a;
	this->size = size;
}
double* arrSort::merge(double c[], int sizec, double d[], int sized) {
	double* e = new double[100];
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
double* arrSort::mergeSort() {
	return this->mergeSort(this->a, this->size);
}
double* arrSort::mergeSort(double f[], int sizef) {
	int a = 0, c = sizef;
	int b = (a + c) / 2;
	if (sizef == 1) {
		double* f5 = new double[1];
		f5[0] = f[a];
		return f5;
	}
	else {
		int size1 = b - a;
		int size2 = c - b;
		double f1[100], f2[100];
		for (int i = 0; i < size1; i++) f1[i] = f[i];
		for (int i = 0; i < size2; i++) f2[i] = f[i + b];
		double* f3 = new double[100];
		f3 = this->mergeSort(f1, size1);
		double* f4 = new double[100];
		f4 = this->mergeSort(f2, size2);
		double* f5 = this->merge(f3, size1, f4, size2);
		return f5;
	}
}
