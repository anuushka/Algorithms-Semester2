#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> graph;
vector<char> seen;
vector<int> matchNM;

bool dfs(int u, int M)
{
    for (int v = 0; v < M; ++v)
    {
        if (graph[u][v] && seen[v] == false)
        {
            seen[v] = 1;

            if (matchNM[v] == -1 ||
                dfs(matchNM[v], M))
            {
                matchNM[v] = u;
                return true;
            }
        }
    }
    return false;
}

int max_matching(int N, int M)
{
    for (int u = 0; u < N; ++u)
    {
        seen.assign(M, 0);
        dfs(u, M);
    }

    return M - std::count(matchNM.begin(), matchNM.end(), -1);
}


int main()
{
    ifstream fin("matching.in");
    ofstream fout("matching.out");

    int N = 0, M = 0, k = 0;
    fin >> N >> M >> k;
    matchNM.assign(M, -1);
    seen.assign(M, 0);
    
    graph.resize(N);
	for (int i = 0; i < N; ++i)
    	graph[i].resize(M);
	
    for(int i = 0; i < N; i++)
    	for(int j = 0; j < M; j++)
    		graph[i][j] = 0;

    for (int i = 0; i < k; ++i)
    {
        int u = 0, v = 0;
        fin >> u >> v;
        graph[u - 1][v - 1] = 1;
    }

    fout << max_matching(N, M);

    return 0;
}
