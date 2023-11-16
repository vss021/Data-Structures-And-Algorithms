#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void depthFirstSearch(int start, unordered_map<int, bool>& visited, stack<int>& st, vector<int> adj[]) {
        visited[start] = true;

        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                depthFirstSearch(neighbor, visited, st, adj);
            }
        }

        // It is a leaf (last node) in the graph
        st.push(start);
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        stack<int> st;
        vector<int> result;

        // 1. Handling non-connecting components
        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                depthFirstSearch(u, visited, st, adj);
            }
        }

        // 2. Pop stack
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

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

    Solution sol;
    vector<int> result = sol.topoSort(V, adj);

    // Print the topological order
    if (!result.empty()) {
        cout << "Topological Order:";
        for (int u : result) {
            cout << " " << u;
        }
        cout << endl;
    }

    return 0;
}
