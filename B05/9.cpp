#include <iostream>
#include <stdlib.h>
using namespace std;

int random(int n)
{
	return rand()%n;
}

int main()
{
	int n;
	cin >> n;
	cout << random(n);
	return 0;
}
