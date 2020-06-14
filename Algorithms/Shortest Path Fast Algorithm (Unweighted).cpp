#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	std::vector<int> adj[n];
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	
	std::queue<int> q;
	q.push(0);
	std::vector<int> d(n, INT32_MAX);
	d[0] = 0;
	
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(auto u: adj[v])
		{
			if(d[u] == INT32_MAX)
			{
				d[u] = d[v] + 1;
				q.push(u);
			}
			
		}
	}
	
	for(auto u: d)
	{
		cout << u << ' ';
	}
	
}
