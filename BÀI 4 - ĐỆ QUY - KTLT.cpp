#include <iostream>
#include <math.h>
using namespace std;

float y(int n);
float x(int n)
{
    if (n == 0)
        return 1;
    else
        return x(n - 1) / 3.0 + y(n - 1) / 2.0 + 27;
}

float y(int n)
{
    if (n == 0)
        return 2;
    else
        return x(n - 1) / 5.0 + y(n - 1) / 7.0 + 11;
}

int main()
{
    int n;
    cout << "Nhập vào giá trị n: ";
    cin >> n;
    cout << "Giá trị của x(" << n << ")= " << x(n) << endl;
    cout << "Giá trị của y(" << n << ")= " << y(n) << endl;
    return 0;
}