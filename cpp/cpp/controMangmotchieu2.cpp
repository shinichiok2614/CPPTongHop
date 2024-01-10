#include <iostream>
using namespace std;
int main()
{
    int col = 3;
    int *a;
    for (int i = 0; i < col; i++)
    {
        a[i]=new int;
    }
    return 0;
}