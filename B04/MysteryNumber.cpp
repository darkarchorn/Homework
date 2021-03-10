#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void getData(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n+1];
    getData(a, n);
    getData(b, n+1);
    sort(a, a+n);
    sort(b, b+n+1);
    for(int i = 0; i < n+1; i++)
    {
        if(a[i] != b[i])
        {
            cout << b[i];
            break;
        }
    }
    return 0;
}
