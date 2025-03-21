#include <iostream>
#include <math.h>
using namespace std;

int GT(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * GT(n - 1);
}

float Tohop(int n, int k)
{
    if ((n == 0 && k == 0) || (n == 1 && k == 1))
        return 1;
    else
        return GT(n) / (GT(n - k) * GT(k));
}

int main()
{
    int n, k;
    cout << "Nhập vào giá trị n và k: ";
    cin >> n >> k;
    cout << "Giá trị của tổ hợp là: " << Tohop(n, k);
    return 0;
}