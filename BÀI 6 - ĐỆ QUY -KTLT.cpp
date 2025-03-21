#include <iostream>
#include <math.h>
using namespace std;

int x(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int s = 0;
    for (int i = 0;i < n;i++)
    {
        s += (n - i) * x(i);
    }
    return s;
}


int main()
{
    int n;
    cout << "Nhập vào n: ";
    cin >> n;
    cout << "Giá trị của x(" << n << ")= " << x(n) << endl;
    return 0;
}