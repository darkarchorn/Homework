
#include <iostream>
using namespace std;

bool KiemTra(int k, int n);
int ToHop(int k, int n);
void nhapKN(int k[], int n[], int *soPhanTu);


int main()
{
	int k[100], n[100];
	int* soPhanTu = new int;
    nhapKN(k, n, soPhanTu);
	for (int i = 0; i < *soPhanTu; i++)
	{
	    if(KiemTra(k[i], n[i]))
            cout << ToHop(k[i], n[i]) << endl;
        else cout << 0 << endl;
	}
	return 0;
}

bool KiemTra(int k, int n)
{
	return(k <= n && k >= 0 && n >= 1 && n <= 20);
}

int ToHop(int k, int n)
{
	int ans = 1;
	for (int i = 1; i <= k; i++, n--)
	{
		ans = ans*n/i;
	}
	return ans;
}

void nhapKN(int k[], int n[], int *soPhanTu)
{
    int t = 0;
	for(int i = 0; i <= *soPhanTu; i++)
	{
		cin >> k[i] >> n[i];
		if(k[i] != -1 && n[i] != -1)
        {
            t++;
        }
        else break;
	}
	*soPhanTu = t;
}
