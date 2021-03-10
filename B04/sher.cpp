#include <iostream>
#include <vector>
using namespace std;

string balancedSums(vector<int> arr);

int main()
{
	int q_num;
	cin >> q_num;
	for (int i = 0; i < q_num; i++)
	{
		int n;
		vector<int> arr;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			arr.push_back(x);
		}
		cout << balancedSums(arr) << endl;
	}
	return 0;
}

string balancedSums(vector<int> arr)
{
    int n = arr.size();
        int sum = 0, leftSum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(leftSum == sum - leftSum - arr[i])
        {
            return "YES";
        }
        leftSum += arr[i];
    }
    return "NO";
}
