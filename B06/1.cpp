#include <iostream>
using namespace std;

void f(int a[])
{
	cout << &a << endl << &a[0];
}

int main()
{
	int A[3] = {1, 2, 3};
	cout << "Trong ham main: " << endl;
	cout << &A << endl << &A[0] << endl;
	cout << "Tu ham f: " << endl;
	f(A);
	return 0;
}
