#include <iostream>
using namespace std;
class Complex {
private:
	double real;
	double imaginary;
public:
	Complex();
	Complex(double, double);
	void setReal(double);
	void setImaginary(double);
	double getReal();
	double getImaginary();
	Complex operator+(double);
	Complex operator+(Complex);
	Complex operator-(double);
	Complex operator-(Complex);
	Complex operator*(double);
	Complex operator*(Complex);
	Complex operator/(double);
	Complex operator/(Complex);
	friend Complex operator+(double, Complex);
	friend Complex operator-(double, Complex);
	friend Complex operator*(double, Complex);
	friend Complex operator/(double, Complex);
};
Complex::Complex() { };
Complex::Complex(double a, double b) {
	real = a;
	imaginary = b;
}
void Complex::setReal(double a) {
	this->real = a;
}
void Complex::setImaginary(double a) {
	this->imaginary = a;
}
double Complex::getReal() {
	return this->real;
}
double Complex::getImaginary() {
	return this->imaginary;
}
Complex Complex::operator+(double a) {
	return Complex(this->getReal() + a, this->getImaginary());
}
Complex Complex::operator+(Complex a) {
	return Complex(this->getReal() + a.getReal(), this->getImaginary() + a.getImaginary());
}
Complex Complex::operator-(double a) {
	return Complex(this->getReal() - a, this->getImaginary());
}
Complex Complex::operator-(Complex a) {
	return Complex(this->getReal() - a.getReal(), this->getImaginary() - a.getImaginary());
}
Complex Complex::operator*(double a) {
	return Complex(this->getReal() * a, this->getImaginary() * a);
}
//(a+bi)/(c+di)=((a+bi)(c-di))/(c2+d2)
Complex Complex::operator/(Complex a) {
	double real1, real2;
	double imaginary1, imaginary2;
	Complex c = Complex(this->getReal(), this->getImaginary()) * Complex(a.getReal(), -a.getImaginary());
	double d = this->getReal() * this->getReal() + a.getImaginary() * a.getImaginary();
	return c / d;
}
Complex Complex::operator/(double a) {
	return Complex(this->getReal() / a, this->getImaginary() / a);
}
//(a+bi)(c+di)=ac-bd + (ad+bc)i
Complex Complex::operator*(Complex a) {
	double real1 = this->getReal() * a.getReal() - this->getImaginary() * a.getImaginary();
	double imaginary1 = this->getReal() * a.getImaginary() + this->getImaginary() * a.getReal();
	return Complex(real1, imaginary1);
}
Complex operator+(double a, Complex b) {
	return Complex(b.getReal() + a, b.getImaginary());
}
Complex operator-(double a, Complex b) {
	return Complex(a - b.getReal(), 0 - b.getImaginary());
}
Complex operator*(double a, Complex b) {
	return Complex(b.getReal() * a, b.getImaginary());
}
Complex operator/(double a, Complex b) {
	return Complex(a, 0) / b;
}

int main() {
	//tools>options>debugging>Automatically close the console when debugging stops.
	cout << "hlw" << endl;
	Complex a(2, 3), b(5, 6);

	Complex c = a + b;
	cout << "	Complex c = a + b;\n";
	cout << c.getReal() << " " << c.getImaginary() << endl;

	Complex c1 = a + 2;
	cout << "	Complex c1 = a + 2;\n";
	cout << c1.getReal() << " " << c1.getImaginary() << endl;

	Complex c10 = a- b;
	cout << "	Complex c10 = a- b;\n";
	cout << c10.getReal() << " " << c10.getImaginary() << endl;

	Complex c11 = a - 2;
	cout << "	Complex c11 = a - 2;\n";
	cout << c11.getReal() << " " << c11.getImaginary() << endl;

	Complex c2 = a * 2;
	cout << "	Complex c2 = a * 2;\n";
	cout << c2.getReal() << " " << c2.getImaginary() << endl;

	Complex c3 = a * b;
	cout << "	Complex c3 = a * b;\n";
	cout << c3.getReal() << " " << c3.getImaginary() << endl;

	Complex c4 = a.operator*(b);
	cout << "	Complex c4 = a.operator*(b);\n";
	cout << c4.getReal() << " " << c4.getImaginary() << endl;

	Complex c40 = a / b;
	cout << "	Complex c40 = a / b;\n";
	cout << c40.getReal() << " " << c40.getImaginary() << endl;

	Complex c5 = 3 + a;
	cout << "	Complex c5 = 3 + a;\n";
	cout << c5.getReal() << " " << c5.getImaginary() << endl;

	Complex c50 = 3 - a;
	cout << "	Complex c50 = 3 - a;\n";
	cout << c50.getReal() << " " << c50.getImaginary() << endl;

	Complex c6 = 3 * a;
	cout << "	Complex c6 = 3 * a;\n";
	cout << c6.getReal() << " " << c6.getImaginary() << endl;

	Complex c7 = 5 / b;
	cout << "	Complex c7 = 5 / b;\n";
	cout << c7.getReal() << " " << c7.getImaginary() << endl;
	return 0;
}