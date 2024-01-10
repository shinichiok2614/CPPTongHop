#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main() {
	vector<string>	x{ "a","b","c" }; //chiều tăng: trái qua phải [0][1][2]
	vector<string>	y{ "d","e" };
	vector<string>	z{ "m","n","t" };
	vector<string>	Si{ "a","d","m" };
	vector<string>	Si1{ "a","d","t" };
	vector<string>	Si2{ "a","e","t" };
	vector<string>	Si3{ "c","e","t" };
	auto printvt1 = [](const vector<string>& vt1) {
		for (const auto& p : vt1) {
			cout << p << " ";
		}
		cout << endl;
	};
	/*auto pos = find(x.begin(), x.end(), "d");
	if (pos != x.end()) {
		cout << "pos:" << pos - x.begin() << endl;
	}*/
	auto nextGen = [](const vector<string>& vt1, const vector<string>& vt2, const vector<string>& vt3, const vector<string>& Si) {
		vector<string>	Si1;
		auto pos3 = find(vt3.begin(), vt3.end(), Si.at(2));
		auto pos2 = find(vt2.begin(), vt2.end(), Si.at(1));
		auto pos1 = find(vt1.begin(), vt1.end(), Si.at(0));
		if (pos3 != vt3.end()) {                                                 //nếu pos3 tồn tại
			if (pos3 - vt3.begin() + 1 == vt3.size()) {                          //nếu pos3 là pt cuối
				if (pos2 != vt2.end()) {
					if (pos2 - vt2.begin() + 1 == vt2.size()) {                       //nếu pos2 là pt cuối
						if (pos1 != vt1.end()) {
							if (pos1 - vt1.begin() + 1 == vt1.size()) {                   //nếu pos1  là pt cuối
								return Si;                                              //thì trả lại chính Si
							}
							else {                                                      //nếu pos1 khác pt cuối
								Si1.push_back(vt1.at(pos1 - vt1.begin() + 1));
								Si1.push_back(vt2.at(0)); //vt2 
								Si1.push_back(vt3.at(0));                 //vt3 reset
							}
						}
					}
					else {                                                          //nếu pos2 khác pt cuối
						Si1.push_back(Si.at(0));
						Si1.push_back(vt2.at(pos2 - vt2.begin() + 1)); //vt2 ++
						Si1.push_back(vt3.at(0));                 //vt3 reset
					}
				}
			}
			else {
				Si1.push_back(Si.at(0));
				Si1.push_back(Si.at(1));
				Si1.push_back(vt3.at(pos3 - vt3.begin() + 1));
			}
		}
		return Si1;
	};
	//cout << x.at(0);
	//printvt1(nextGen(x, y, z, Si));
	//printvt1(nextGen(x, y, z, Si1));
	//printvt1(nextGen(x, y, z, Si2));
	//printvt1(nextGen(x, y, z, Si3));
	while (true) {
		auto SiNext = nextGen(x, y, z, Si);
		if (SiNext != Si) {
			printvt1(SiNext);
			Si = SiNext;
		}
		else break;
	}
	return 1;
}