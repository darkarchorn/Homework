#include <iostream>
using namespace std;

string reverse(string s)
{
	string r = s;
	int i = 0, j = r.size()-1;
	while(i < j)
	{
		swap(r[i], r[j]);
		i++;
		j--;
	}
	return r;
}

int main()
{
	int n;
	cin >> n;
	string v[100];
	string rev_v[100];
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		rev_v[i] = reverse(v[i]);
	}

	for(int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(v[i] == rev_v[j])
            {
                cout << v[i].size() << ' ' << v[i][v[i].size()/2];
            }
        }
    }
	return 0;
}
