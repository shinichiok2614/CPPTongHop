#include <iostream>
#include <vector>
#include<numeric>
#include<cmath>
#include<algorithm>
using namespace std;
class Item {
private:
	double w; //trong luong
	double v; //gia tri
	double d; //don gia
public:
	Item(double w, double v) :w(w), v(v) {
		d = v / w;
	}
	double getW();
	double getV();
	double getD();
};
double Item::getW() {
	return w;
}
double Item::getV() {
	return v;
}
double Item::getD() {
	return d;
}
class Bag {
private:
	int i;
	int n;
	double wptr;      //khoi luong hien tai
	double vptr;      //gia tri hien tai
	double great;      //gia tri hien tai
	double m;         //trong luong
	vector<Item> h;   //source
	vector<Item> result;
public:
	Bag(double m, vector<Item> h) :m(m), h(h) {
		sort(h.begin(), h.end(), [](Item& a, Item& b) {
			return a.getD() > b.getD();
			});

		i = 0;
		n = h.size() - 1;
		wptr = 0;
		vptr = 0;
		great = 0;
		bab(i);
		getResult();
	}
	void getResult();
	void bab(int i);
};
void Bag::getResult() {
	for (Item& p : h) {
		cout << p.getW() << ";" << p.getV() << ";" << p.getD() << " ";
	}
	cout << endl;
	for (Item& p : result) {
		cout << p.getW() << ";" << p.getV() << ";" << p.getD() << " ";
	}
	cout << endl;
}
void Bag::bab(int i) {
	int t, g;
	double t1 = (m - wptr) / h.at(i).getW();
	t = floor(t1);                  //lam tron xuong
	for (int j = t; j >= 0; j--) {
		wptr += h[i].getW();            //cap nhat tt moi
		vptr += h[i].getV();
		if (i == n) {               //dk chap nhan
			if (vptr > great) {              //dk dung
				great = wptr;
			}
		}
		else
		{
			g = vptr + h[i + 1].getV() * (m - wptr) / h[i + 1].getW();
			cout << wptr << ";" << vptr << ";" << g << " ";
			if (g > great) {
				bab(i + 1);
			}
		}
		wptr -= h[i].getW();           //tra lai trang thai cu
		vptr -= h[i].getV();
	}
}
int main() {
	Item it1(5, 10);
	Item it2(3, 5);
	Item it3(2, 3);
	Item it4(4, 6);
	vector<Item> House;
	House.push_back(it1);
	House.push_back(it2);
	House.push_back(it3);
	House.push_back(it4);
	Bag b(8, House);
	return 1;
}