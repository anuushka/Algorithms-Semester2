#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<long long, pair<long long, long long>>> G;
vector<long long> parent;
long long n, m;

bool sort_weight(const pair<long long, pair<long long, long long>> &p1, const pair<long long, pair<long long, long long>> &p2) 
{
    return p1.first < p2.first;
}

long long find_DSU(long long v) 
{
    if (v == parent[v]) 
    return v;
    return parent[v] = find_DSU(parent[v]);
}

void union_DSU(long long a, long long b) 
{
    a = find_DSU(a);
    b = find_DSU(b);
    if (a != b) 
	{
        parent[b] = a;
    }
}

int main() {


    cin >> n >> m;
    G.resize(m);
    parent.resize(n + 1);
    long long MST_weight = 0;
    long long x, y, z;
    for (long long i = 0; i < m; i++) {
        cin >> x >> y >> z;
        G[i].second.first = x;
        G[i].second.second = y;
        G[i].first = z;
    }
    for (long long i = 0; i < n; i++) {
        parent[i] = i;
    }

    sort(G.begin(), G.end(), sort_weight);
    for (long long i = 0; i < m; i++) {
        long long a = G[i].second.first;
        long long b = G[i].second.second;
        long long w = G[i].first;

        if (find_DSU(a) != find_DSU(b)) {
            MST_weight += w;
            union_DSU(a, b);
        }
    }

    cout << MST_weight;
    return 0;
}
