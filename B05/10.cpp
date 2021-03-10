#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void random(int n, int a[])
{
    srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%49;
	}
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	random(n,a);
	for (int i = 0; i < n-2; i++)
	{
		for(int j = i+1; j < n-1; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				if((a[i]+a[j]+a[k]) % 25 == 0)
					cout << a[i] << ' ' << a[j] << ' ' << a[k] << endl;
			}
		}
	}

	return 0;
}
