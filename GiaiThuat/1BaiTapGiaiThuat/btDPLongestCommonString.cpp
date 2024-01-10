#include <iostream>
#include<vector>
using namespace std;
class td {
public:
	int a;
	int b;
};
string longestCommonStringDP(string a, string b) {
	vector<int> c;
	vector<vector<int>> d;
	int cmax = 0;
	int ci = b.length();
	int cj = a.length();
	string e = "";
	c.assign(a.length() + 1, 0);
	auto printvt1 = [](const vector<int>& vt1) {
		for (const auto& p : vt1) {
			cout << p << " ";
		}
		cout << endl;
	};
	printvt1(c);
	d.push_back(c);
	cout << "d0" << endl;
	printvt1(d[0]);

	for (int i = 0; i < b.length(); i++) {
		vector<int> c1{ 0 };
		for (int j = 0; j < a.length(); j++) {
			if (b[i] == a[j]) {
				c1.push_back(d[i][j] + 1);
				if (c1.back() == cmax && j < cj) {
					e.pop_back();
					e.push_back(a[j]);
					ci = i;
				}
				else {
					if (i != ci) {
						if (c1.back() > cmax) {
							e.push_back(a[j]);
							cmax = c1.back();
							ci = i;
							cj = j;
						}
					}
				}
			}
			else {
				c1.push_back((c1[j] > d[i][j + 1]) ? c1[j] : d[i][j + 1]);
			}
		}
		d.push_back(c1);
		printvt1(c1);
	}

	auto printvt2 = [&printvt1](const vector<vector<int>>& vt2) {
		for (const auto& p : vt2) {
			printvt1(p);
		}
	};
	cout << "d\n";
	printvt2(d);

	//truy vet
	//string e = "";
	//int e1 = a.length();
	//for (int i = 0; i < d.size(); i++) {
	//	for (int j = 0; j < d[0].size(); j++) {

	//	}
	//}
	return e;
}
int main()
{
	std::cout << "Hello World!\n";
	string a = "khoax hoc";
	string b = "xha noic";
	cout << longestCommonStringDP(a, b); //ha oc
}