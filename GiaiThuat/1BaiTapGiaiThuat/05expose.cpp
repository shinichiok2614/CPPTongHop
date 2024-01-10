#include <iostream>
using namespace std;
int power(int x, unsigned int y)
{
	int temp;
	if (y == 0)
		return 1;
	temp = power(x, y / 2);
	if (y % 2 == 0)
		return temp * temp;
	else
		return x * temp * temp;
}
int main(void)
{
	int x = 2;
	unsigned n = 3;
	int result = power(x, n);
	cout << result << endl;
	return 0;
}
