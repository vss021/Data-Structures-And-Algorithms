#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool checkForCycleUsingDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, vector<int> adj[]) {
    visited[node] = true;
    dfsVisited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            bool isLoop = checkForCycleUsingDFS(neighbor, visited, dfsVisited, adj);

            if (isLoop) {
                return true;
            }
        } else if (dfsVisited[neighbor]) {
            return true;
        }
    }

    dfsVisited[node] = false;

    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    unordered_map<int, bool> visited;

    unordered_map<int, bool> dfsVisited;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (checkForCycleUsingDFS(i, visited, dfsVisited, adj)) {
                return true;
            }
        }
    }

    return false;
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
        // Do not add the reverse edge for directed graphs
    }

    if (isCyclic(V, adj)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}
