#pragma once
#include <iostream>
using namespace std;
class Player {
private:
	string name;
	int number;
	double ability;
	double age;
	bool isforeign;
	int hs;
public:
	Player(string, int, double, double, bool,int);
	void setname(string);
	void setnumber(int);
	void setability(double);
	void setage(double);
	void setisforeign(bool);
	void seths(int);
	string getname();
	int getnumber();
	double getability();
	double getage();
	bool getisforeign();
	int geths();
};
Player::Player(string a, int b, double c, double d, bool e, int f) {
	this->name = a;
	this->number = b;
	this->ability = c;
	this->age = d;
	this->isforeign = e;
	this->hs = f;
}
void Player::setname(string a) {
	this->name = a;
}
void Player::setnumber(int a) {
	this->number = a;
}
void Player::setability(double a) {
	this->ability = a;
}
void Player::setage(double a) {
	this->age;
}
void Player::setisforeign(bool a) {
	this->isforeign = a;
}
void Player::seths(int a) {
	this->hs = a;
}
string Player::getname() {
	return this->name;
}
int Player::getnumber() {
	return this->number;
}
double Player::getability() {
	return this->ability;
}
double Player::getage() {
	return this->age;
}
bool Player::getisforeign() {
	return this->isforeign;
}
int Player::geths() {
	return this->hs;
}