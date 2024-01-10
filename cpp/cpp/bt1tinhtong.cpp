#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x, n;
    float sn, s;
    s = 1;
    cout << "nhap x" << endl;
    cin >> x;
    cout << "nhap n" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sn = (pow(x, i) / (i + 1));
        s += sn;
    }
    cout << "s=";
    cout << s << endl;

    return 0;
}