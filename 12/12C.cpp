#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
 
struct Edge 
{
    int u, v, capacity, flow, id;
};
vector<vector<int>> graph;
vector<Edge> edges;
vector<int> ptr;
vector<int> level;
vector<vector<int>> path;
 
int n, m, s = 0, t = 0;
//Finds if more flow can be sent from s to t. 
// Also assigns levels to nodes. 
bool bfs() {
    queue<int> q;
    level.assign(n, 0);
    q.push(s);
    level[s] = 1;
    while (!q.empty() && !level[t]) {
        int u = q.front();
        q.pop();
        for (auto& e : graph[u]) {
            if (!level[edges[e].v] && edges[e].capacity > edges[e].flow) {
                q.push(edges[e].v);
                level[edges[e].v] = level[u] + 1;
            }
        }
    }
    return level[t];
}
 
int dfs(int vertex, int flow) {
    if (!flow)
        return 0;
	//if we reach sink, we return flow
    if (vertex == t)    
        return flow;
    // Traverse all adjacent edges one -by - one. 
    while (ptr[vertex] < graph[vertex].size()) {
    	//pick next edge from adj list vertex
        int e = graph[vertex][ptr[vertex]];
        if (level[vertex] + 1 == level[edges[e].v]){
        // find minimum flow from vertex to t 
            int temp_flow = dfs(edges[e].v, min(flow, edges[e].capacity - edges[e].flow));
           // flow is greater than zero 
		   if (temp_flow) {
		   	    // add flow  to current edge 
                edges[e].flow += temp_flow;
                // subtract flow from reverse edge 
                // of current edge 
                edges[e ^ 1].flow -= temp_flow;
                return temp_flow;
            }
        }
        ptr[vertex]++; // count of edges explored from i. it is to keep track of next edge to be explored
    }
    return 0;
}
//Output order: flow, number of edges, edge ID s
int decompose(int vertex, int cur_flow) 
{
    if (vertex == t) 
	{
        path.emplace_back();
        return cur_flow;
    }
    //find path from s -> t
    for (auto& e : graph[vertex]) 
	{
		//If the flow is still positive, we find a path at every step:
        if (edges[e].flow > 0) 
		{
            int result = decompose(edges[e].v, min(cur_flow, edges[e].flow));
            if (result) 
			{
                path.back().push_back(edges[e].id); //edge id
                if (vertex == s) 
				{
                    path.back().push_back(path[path.size() - 1].size()); //number of edges
                    path.back().push_back(result);//flow
                    reverse(path.back().begin(), path.back().end());
                }
                edges[e].flow -= result;
                return result;
            }
        }
    }
    return 0;
}
 
int main() {
    ifstream fin("decomposition.in");
    ofstream fout("decomposition.out");
    fin >> n >> m;
    graph.resize(n);
    ptr.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v, capacity;
        fin >> u >> v >> capacity;
        graph[u - 1].push_back(edges.size());
        edges.emplace_back(Edge{u - 1, v - 1, capacity, 0, i + 1});
        graph[v - 1].push_back(edges.size());
        edges.emplace_back(Edge{v - 1, u - 1, 0, 0, i + 1});
    }
    t = n - 1;
    while (bfs()) {
        while (dfs(s, INT_MAX));
        ptr.assign(n, 0);
    }
    while (decompose(s, INT_MAX));
    fout << path.size() << "\n";
    for (auto& i : path) {
        for (auto& j : i)
            fout << j << ' ';
        fout << '\n';
    }
    return 0;
}
