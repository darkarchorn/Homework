#include <iostream>
#include <cmath>
using namespace std;

void EratosthenesSeive(const int n);

int main()
{
	int n;
	cin >> n;
	EratosthenesSeive(n);
	return 0;
}

void EratosthenesSeive(const int n)
{
	bool arr[n];
	for (int i = 0; i <= n; i++)
		arr[i] = true;
	for (int i = 2; i < sqrt(n); i++)
	{
		if(arr[i])
			for (int j = i*i; j <= n; j = j+i)
			{
				arr[j] = false;
			}
	}

	for (int i = 2; i <= n; i++)
	{
		if(arr[i] == true) cout << i << ' ';
	}
}
