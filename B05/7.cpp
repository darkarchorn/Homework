#include <iostream>
using namespace std;

void print(int m, int n)
{
	for (int i = 0; i < m; i++)
		cout << ' ';
	for (int j = 0; j < n; j++)
		cout << '*';
}

int main()
{
	int line;
	cin >> line;
	for (int i = 0; i < line; i++)
	{
		print(line-i, 2*i-1);
		cout << endl;
	}
	return 0;
}
