#include <iostream>
#include <cmath>
using namespace std;

int rnd_lib(float a)
{
	return round(a);
}

int rnd(float a)
{
    float r = a-(int)a;
    if(r >= 0.5) return a+1;
    return a;
}

int main()
{
	float a;
	cin >> a;
	cout << rnd_lib(a) << endl;
	cout << rnd(a);
	return 0;
}
