#include<iostream>
using namespace std;
class GFG {
public:
	int fib(int n)
	{
		const int a = 9;//loi nay chua sua duoc
		int f[a + 2];
		int i;
		f[0] = 0;
		f[1] = 1;
		for (i = 2; i <= n; i++)
		{
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
};
int main()
{
	GFG g;
	int n = 9;
	cout << g.fib(n);
	return 0;
}
