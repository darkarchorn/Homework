#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

void TandemNumbers(int i, int j, string s, int n)
{
    string str = s.substr(i-1, j);
    int tmp_pos = j, l = i-j;
    int ans = 1;
    cout << str << endl;

    for (int k = tmp_pos; k < n; k++)
    {
        cout <<"ans: " << ans << ' ' <<  ' ' << "k: " << k << endl;
        if(s.substr(k, k+l+1) == str)
        {
            ans++;
            tmp_pos = k+l+2;
        }
    }

}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0;i < m; i++)
    {
        cin >> x >> y;
        cout << TandemNumbers(x, y, s, n) << endl;
    }
    return 0;
}
