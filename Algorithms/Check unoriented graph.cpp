#include<iostream> 
#include<vector>
using namespace std;

int main()
{

	int n;
	cin >> n;
	vector<vector<int>> arr;
	arr.resize(n);
	
	for(int i = 0; i < n; i++)
	{
		arr[i].resize(n);
	}
	
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if((arr[i][j] != arr[j][i]) || (arr[j][j] == 1))
			{
				cout << "NO" << "\n";
				return 0;
			}
			else 
			{
			}
		
		}
	}
	
	cout << "YES" << "\n"; 
	return 0;
	
}
