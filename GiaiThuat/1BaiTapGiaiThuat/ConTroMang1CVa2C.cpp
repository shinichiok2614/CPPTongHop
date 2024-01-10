#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<double> a1 = { 3,5,6 };
	vector<double> a2 = { 4,6,7 };
	vector<vector<double>> arr;
	arr.push_back(a1);
	arr.push_back(a2);
	auto printvt1 = [](const vector<double>& p) {
		//cout << *(&p[2]) << endl;
		//cout << p[0] << endl;
		for (auto& p1 : p) {
			cout << p1 << " ";
		}
		cout << endl;
	};
	auto printvt2 = [](const vector<vector<double>>& p) {
		//cout << p[1][2] << endl;
		for (auto& p1 : p) {
			for (auto& p2 : p1) {
				cout << p2 << " ";
			}
			cout << endl;
		}
	};
	//printvt1(a1);
	printvt2(arr);
	/*const int row = 5;
	const int col = 5;
	double C[row][col] = {
		{0,3,14,18,15},
		{3,0,4,22,20},
		{17,9,0,16,4},
		{6,2,7,0,12},
		{9,15,11,5,0}
	};
	auto printArr2D = [](double arr[][5], int row, int col) {
		cout << arr[2][2] << endl;
		double s = 0;
		double g = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				s += arr[i][j];
			}
		}

		return 1;
	};
	printArr2D(C, 5, 5);*/

	return 1;
}