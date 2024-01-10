#include <iostream>
using namespace std;
//da hoan thanh
int arrminfc(double a[], int asize, double notmin) {
	double min = notmin;
	int p = 0;
	int i1 = 0;
	while (i1 < asize) {
		if (a[i1] > notmin)
		{
			min = a[i1];
			p = i1;
			break;
		}
		i1++;
	}
	for (int i = 0; i < asize; i++) {
		if (a[i] < min && a[i]>notmin) {
			min = a[i];
			p = i;
		}
	}
	return p;
}
int main() {
	cout << "HLW\n";
	const int ROW = 7, COL = 7;
	double arr[ROW][COL] =
	{
		{0,3,6,0,0,0,0},
		{3,0,2,4,0,0,0},
		{6,2,0,1,4,2,0},
		{0,4,1,0,2,0,4},
		{0,0,4,2,0,2,1},
		{0,0,2,0,2,0,4},
		{0,0,0,4,1,4,0}
	};
	int kq[COL];
	kq[0] = 0;
	int kqpoint = 1;
	double s = arr[0][0];
	double arrmin = 0;
	int arrminpoint = 0;
	double arr1[COL];
	int i3;
	for (int i = 1; i < ROW; i++) { //xet row
		i3 = 0;
		int kqgt1 = kq[kqpoint - 1];
		for (int i1 = 0; i1 < COL; i1++) //xet col
		{
			if (arr[kqgt1][i1] > 0)
				//arr1[i1] = s + arr[i - 1][i1];
				arr1[i1] = s + arr[kqgt1][i1];
		}
		for (int i2 = 0; i2 < kqpoint; i2++) {
			int kqgt = kq[i2];
			arr1[kqgt] = 0;
		}
		arrminpoint = arrminfc(arr1, COL, 0);
		kq[i] = arrminpoint;
		s = arr1[arrminpoint];
		kqpoint++;
		for (int i = 0; i < COL; i++) {
			cout << arr1[i] << " ";
			arr1[i] = 0; //xoa du lieu
		}
		cout << endl;
		cout << "->" << kq[i] << endl;
	}
	cout << s;
	return 1;
}
