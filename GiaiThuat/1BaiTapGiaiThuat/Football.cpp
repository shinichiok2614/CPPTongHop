#include <iostream>
using namespace std;
//chua hoàn thành
class Player {
private:
	int number;
	int ability;
	int age;
	bool isforeign;
	int hs;
public:
	void setnumber(int);
	void setability(int);
	void setage(int);
	void setisforeign(bool);
	void seths(int);
	int getnumber();
	int getability();
	int getage();
	bool getisforeign();
	int geths();
};
void Player::setnumber(int a) {
	this->number = a;
}
void Player::setability(int a) {
	this->ability = a;
}
void Player::setage(int a) {
	this->age=a;
}
void Player::setisforeign(bool a) {
	this->isforeign = a;
}
void Player::seths(int a) {
	this->hs = a;
}
int Player::getnumber() {
	return this->number;
}
int Player::getability() {
	return this->ability;
}
int Player::getage() {
	return this->age;
}
bool Player::getisforeign() {
	return this->isforeign;
}
int Player::geths() {
	return this->hs;
}
Player setPlayer() {//ham gan cac gia tri ngau nhien theo yc cua de bai
	Player p;
	int c = rand() % (99 - 1 + 1) + 1; //so ao
	int c1 = 1; //ability
	while (c1 % 5 != 0)
	{
		c1 = rand() % (999 - 100 + 1) + 1;
	}
	int c2 = rand() % (35 - 16 + 1) + 16;//age
	int c3 = rand() % 2;
	bool isforeign;
	bool c4 = (c3 == 1) ? 1 : 0;//isforeign
	int c5;//hs
	if (c2 < 20) c5=3;
	else {
		if (c2 < 30) c5=2;
		else
		{
			c5=1;
		}
	}
	p.setnumber(c);
	p.setability(c1);
	p.setage(c2);
	p.setisforeign(c4);
	p.seths(c5);
	return p;
}
void getPlayer(Player p) {
	//cout << "number:" << p.getnumber() << endl;
	//cout << "ability:" << p.getability() << endl;
	//cout << "age:" << p.getage() << endl;
	//cout << "isforeign:" << p.getisforeign() << endl;
	//cout << "hs:" << p.geths() << endl;

	cout << "number: " << p.getnumber();
	cout << " ability: " << p.getability();
	cout << " age: " << p.getage();
	cout << " isforeign: " << p.getisforeign();
	cout << " hs: " << p.geths() <<endl;
}
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
int main()
{
	//nếu muốn khởi tạo mảng 1 chiều chứa nhiều đối tượng thì trong đối tượng phải có constructor k tham số
	//phương thức setPlayer nên ở trong class Player
	//nếu là bộ hàm riêng bên ngoài
	//tìm hiểu list và vector nhưng dùng với con trỏ list<Player*> vì list với con trỏ sẽ k tự động tạo vùng nhớ như java
	srand(time(NULL));
	cout << "teamA\n";
	Player* teamA = new Player[11];
	for (int i = 0; i < 11;i++) {
		teamA[i] = setPlayer();
	}
	int* f1 = new int[11];
	int s = 0;
	for (int i = 0; i < 11; i++) {
		f1[i]=teamA[i].getability();
		s += teamA[i].getability();
	}
	arrSort a;
	a.set(f1, 11);
	f1 = a.mergeSort();
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (teamA[j].getability() == f1[i]) getPlayer(teamA[j]);
		}
	}
	cout << "Tong chi so sm cua teamA: " << s << endl;

	cout << "teamB\n";
	Player* teamB = new Player[11];
	for (int i = 0; i < 11; i++) {
		teamB[i] = setPlayer();
	}
	int* f2 = new int[11];
	int s2 = 0;
	for (int i = 0; i < 11; i++) {
		f2[i] = teamB[i].getability();
		s2 += teamB[i].getability();
	}
	a.set(f2, 11);
	f2 = a.mergeSort();
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (teamB[j].getability() == f2[i]) getPlayer(teamB[j]);
		}
	}
	cout << "Tong chi so sm cua teamB: " << s2 << endl;
	if ((s2 - s) > 0) cout << "Vay teamB thang";
	else {
		if ((s2 - s) < 0) cout << "Vay teamA thang";
		else
		{
			cout << "Hai doi hoa";
		}
	}
	
}

