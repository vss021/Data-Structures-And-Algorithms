/*
This is same as kahn's algo 
just check No. v == Count 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void topologicalSort(int V, vector<int> adj[]) {

    // Step 1: Find in-degrees
    vector<int> inDegree(V, 0);
    queue<int> q;

    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Step 2: Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process the queue (BFS)
    // count 
    int count = 0;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // increass
        count++;

        // Update in-degrees of neighbors
        for (int neighbor : adj[frontNode]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check for cycles (if not all vertices are included in the topological order)
    if (count != V) {
        cout << "Graph contains a cycle, topological sort not possible." << endl;
        return ;  // Return an empty vector in case of a cycle
    }

    cout<< "Graph does't have a cycle" << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
    }

    topologicalSort(V, adj);

    return 0;
}
