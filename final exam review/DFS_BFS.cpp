// C++ program to implement BFS and DFS on a graph using vectors
// Handles disconnected graphs by iterating over all unvisited vertices
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// -------------------------------------------------------
// BFS
// -------------------------------------------------------

// BFS for a single connected component
void bfsConnected(vector<vector<int>>& adj, int src, vector<bool>& visited, vector<int>& res) {
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while (!q.empty()) {
        
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // visit all the unvisited neighbours of current node
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

// BFS for all components (handles disconnected graphs)
vector<int> bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> res;
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            bfsConnected(adj, i, visited, res);
    }
    return res;
}

// -------------------------------------------------------
// DFS
// -------------------------------------------------------

void dfsRec(vector<vector<int>>& adj, vector<bool>& visited, int s, vector<int>& res) {
    visited[s] = true;
    res.push_back(s);
    // recursively visit all adjacent vertices that are not visited yet
    for (int i : adj[s])
        if (visited[i] == false)
            dfsRec(adj, visited, i, res);
}

vector<int> dfs(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    // loop through all vertices to handle disconnected graph
    for (int i = 0; i < adj.size(); i++) {
        if (visited[i] == false)
            dfsRec(adj, visited, i, res);
    }
    return res;
}

// -------------------------------------------------------
// Driver Code
// -------------------------------------------------------

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Disconnected graph
    //
    //  1 - 2 - 0 - 3     4 - 5
    //
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 0, 3);
    addEdge(adj, 4, 5);

    vector<int> bfsRes = bfs(adj);
    cout << "BFS result: ";
    for (int i : bfsRes)
        cout << i << " ";
    cout << endl;

    vector<int> dfsRes = dfs(adj);
    cout << "DFS result: ";
    for (int i : dfsRes)
        cout << i << " ";
    cout << endl;

    return 0;
}