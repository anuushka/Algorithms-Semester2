#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 
  
typedef pair<int, int> iPair; 
  
void addEdge(vector <pair<int, int> > adj[], int u, 
                                     int v, int wt) 
{ 
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); 
} 
  
void primMST(vector<pair<int,int> > adj[], int V) 
{ 

    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    int src = 0; 
    vector<int> key(V, INF); 
  
    // To store parent array which in turn store MST 
    vector<int> parent(V, -1); 
  
    // To keep track of vertices included in MST 
    vector<bool> inMST(V, false); 
  
    // Insert source itself in priority queue and initialize 
    // its key as 0. 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
  
    /* Looping till priority queue becomes empty */
    while (!pq.empty()) 
    { 
        // The first vertex in pair is the minimum key 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted key (key must be first item 
        // in pair) 
        int u = pq.top().second; 
        pq.pop(); 
  
        inMST[u] = true; // Include vertex in MST 
  
        // Traverse all adjacent of u 
        for (auto x : adj[u]) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = x.first; 
            int weight = x.second; 
  
            // If v is not in MST and weight of (u,v) is smaller 
            // than current key of v 
            if (inMST[v] == false && key[v] > weight) 
            { 
                // Updating key of v 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
  
    // Print edges of MST using parent array 
    for (int i = 1; i < V; ++i) 
        printf("%d - %d\n", parent[i], i); 
} 
  
// Driver program to test methods of graph class 
int main() 
{ 
    int V = 3; 
    vector<iPair > adj[V]; 
  
    // making above shown graph 
    addEdge(adj, 0, 1, -2); 
    addEdge(adj, 0, 2, 1); 
    addEdge(adj, 1, 2, 10); 
    
    primMST(adj, V); 
  
    return 0; 
} 
