#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int src, dest;
};

class Graph
{
public:
	vector<vector<int> > adjList;
	vector<int> indegree;
	
	Graph(vector<Edge> const &edges, int N)
	{
		adjList.resize(N);
		vector<int> temp(N, 0);
		indegree = temp;

		for (auto &edge: edges)
		{
			adjList[edge.src].push_back(edge.dest);
			indegree[edge.dest]++;
		}
	}
};

bool doTopologicalSort(Graph const &graph, vector<int> &L, int N)
{
	vector<int> indegree = graph.indegree;
	vector<int> S;
	for (int i = 0; i < N; i++) {
		if (!indegree[i]) 
		{
			S.push_back(i);
		}
	}

	while (!S.empty())
	{
		int n = S.back();
		S.pop_back();
		L.push_back(n);

		for (int m : graph.adjList[n])
		{
			indegree[m] -= 1;
			if (!indegree[m]) {
				S.push_back(m);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (indegree[i]) {
			return false;
		}
	}

	return true;
}

int main()
{
	vector<Edge> edges =
	{
		{ 0, 6 }, { 1, 2 }, { 1, 4 }, { 1, 6 }, { 3, 0 }, { 3, 4 },
		{ 5, 1 }, { 7, 0 }, { 7, 1 }
	};
	int N = 8;
	Graph graph(edges, N);
	vector<int> L;
	if (doTopologicalSort(graph, L, N))
	{
		for (int i: L)
			cout << i << " ";
	} else {
		cout << "Graph has at least one cycle. "
				"Topological sorting is not possible";
	}

	return 0;
}
