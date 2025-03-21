#include <iostream>
#include <math.h>
using namespace std;

int f(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return f(n - 1) + f(n - 2);
}

double S(int n)
{
	if (n == 1)
		return 1.0/( 1+f(1));
	else
		return S(n - 1) + double(n) / (1 + f(n));
}

int main()
{
	int n;
	cout << "Nhap vao gia tri n: ";
	cin >> n;
	cout << "Gia tri cua S(" << n << ")= " << S(n) << endl;
	return 0;
}