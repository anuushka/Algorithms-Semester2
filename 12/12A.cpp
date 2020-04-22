#include <fstream>
#include <vector>
#include <queue>
using namespace std;
 
vector <vector <int>> graph;
int u, v;
queue<int> q;
vector<bool> visited;
vector <int> parent;
  
bool BFS(int s, int t)
{ 
	visited.assign(graph.size(), false);
    q.push(s);
    visited[s] = true;
  
    while (!q.empty())
    {
        u = q.front();
        q.pop();
  
        for (v = 0; v < graph.size(); v++)
        {
            if (visited[v] == false && graph[u][v] > 0)
            {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
  
    return visited[t];
}
  
int fordFulkerson(int s, int t)
{  
    int max_flow = 0;
    int path_flow = 0;
     
  
    while (BFS(s, t))
    {
        path_flow = INT32_MAX;
  
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = std::min (path_flow, graph[u][v]);
        }
  
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }
  
        max_flow += path_flow;
    }
  
    return max_flow;
}
  
int main() 
{
    ifstream fin("maxflow.in");
    fstream fout("maxflow.out");
  
    int n, m;
    fin >> n >> m;
    graph.resize(n, vector <int> (n));
    parent.resize(n);
  
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
  
    int u, v, capacity;
    for (int i = 0; i < m; i++)
    {
        fin >> u >> v >> capacity;
        graph[u - 1][v - 1] = capacity;
    }
    fout << fordFulkerson(0, n - 1);
      
    return 0;
}
