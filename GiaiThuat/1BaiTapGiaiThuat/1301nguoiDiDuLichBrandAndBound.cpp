#include <iostream>
#include <vector>
#include<numeric>
#include<cmath>
using namespace std;
class BranchAndBound {
private:
	int i;
	int n;
	double s;
	double s1;
	double great;//giá trị tối ưu nhất của từng lần duyệt
	double g;    //giá trị tối ưu
	double g1;
	double cmin;
	int col;
	vector<int> resultSS; //lưu vết
	vector<int> resultG; //lưu g của mỗi hàng
	vector<int> resultS; //lưu s của mỗi hàng
	vector<int> resultJ; //lưu những vị trí chưa xét
	vector<int> resultJconst; //lưu vị trí col j
	vector<vector<double>> a;
	void bab(int);
	void findCmin();
	void vectorJasc();
	template<class T>
	void printvt1D(vector<T>&);
	template<class T>
	void printvt2D();
public:
	BranchAndBound(vector<vector<double>>& a) : a(a) {
		i = 2;
		n = a.size();
		col = a[i].size();
		resultSS.push_back(1);
		vectorJasc();
		findCmin();
		great = INFINITY;
		bab(i);
	}
};
void BranchAndBound::vectorJasc() {
	for (int i = 1; i < a[0].size(); i++) {
		resultJ.push_back(i);
		resultJconst.push_back(i);
	}
}
void BranchAndBound::findCmin() {
	cmin = INFINITY;
	for (vector<double>& b : a) {
		for (double& c : b) {
			(cmin > c && c != 0) ? cmin = c : 1;
		}
	}
}
template<class T>
void BranchAndBound::printvt1D(vector<T>& a) {
	for (T& b : a) {
		cout << b << " ";
	}
	cout << endl;
}
template<class T>
void BranchAndBound::printvt2D() {
	for (vector<T>& b : a) {
		for (T& c : b) {
			cout << c << " ";
		}
		cout << endl;
	}
}
void BranchAndBound::bab(int i) {
	for (int z = 0; z < n - 2; z++) {
		if (i - 1 == n) {
			printvt1D(resultSS);
			(g < great) ? great = g : 1;
		}
		else {
			g = INFINITY;
			resultG.clear();
			resultS.clear();
			for (int j : resultJ) {
				double a1 = a[resultSS.back() - 1][j];
				if (a1 != 0) {                                    //a[vi tri j vua nay][j]
					s1 = a1 + s;
					g1 = s1 + (n - i + 1) * cmin;
					(g > g1) ? g = g1 : 1;
					cout << s1 << ";" << g1 << " ";
					resultG.push_back(g1);
					resultS.push_back(s1);
				}
			}
			auto posG = find(resultG.begin(), resultG.end(), g); //tim vi tri g min
			if (posG != resultG.end()) {
				int pos = posG - resultG.begin();
				resultSS.push_back(resultJ.at(pos) + 1);          //truy vet DaXet
				resultJ.erase(resultJ.begin() + pos);             // ChuaXet
			}
			s = resultS.at(posG - resultG.begin());
			cout << endl;
			if (g < great) {
				bab(i + 1);
			}
		}
		cout << endl;

	}

}
int main() {
	vector<double> a1 = { 0,3,14,18,15 };
	vector<double> a2 = { 3,0,4,22,20 };
	vector<double> a3 = { 17,9,0,16,4 };
	vector<double> a4 = { 6,2,7,0,12 };
	vector<double> a5 = { 9,15,11,5,0 };
	vector<vector<double>> arr;
	arr.push_back(a1);
	arr.push_back(a2);
	arr.push_back(a3);
	arr.push_back(a4);
	arr.push_back(a5);
	BranchAndBound b(arr);
	return 1;
}