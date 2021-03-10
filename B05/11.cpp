#include <iostream>
using namespace std;

int BiToDec(int n)
{
    int ans = 0, r = 1;
	while(n)
	{
	    int temp = (n%10)*r;
	    ans += temp;
	    r *= 2;
	    n/=10;
	}

	return ans;
}

string DecToBi(int n)
{
	string ans;
	while(n)
	{
		char temp = (char)(n%2 + '0');
		ans = temp + ans;
		n /= 2;
	}
	return ans;
}

int main()
{
	int b, d;
	cin >> b;
	cin >> d;
	cout << BiToDec(b) << endl;
	cout << DecToBi(d);
	return 0;
}
