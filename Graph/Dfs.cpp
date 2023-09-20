#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (!direction) {
            adj[v].push_back(u);
        }
    }

    void printGraph() {
        for (auto i : adj) {
            cout << i.first << "-->";

            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void Dfs(unordered_map<int, bool>& visited, vector<int>& ans, int node) {
        ans.push_back(node);
        visited[node] = true;
        for (int i : adj[node]) {
            if (!visited[i]) {
                Dfs(visited, ans, i);  // Corrected the recursive call here
            }
        }
    }
};

int main() {
    graph g;

    int n;
    cout << "Enter the No. of Nodes " << endl;
    cin >> n;
    int m;
    cout << "Enter the No. of Edges " << endl;
    cin >> m;

    cout << "U and V " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // creating undirected graph
        g.addEdge(u, v, 0);
    }

    g.printGraph();

    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    // if non commenting commponets comes that cases will handle 
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            g.Dfs(visited, component, i);
            ans.push_back(component);
        }
    }

    cout << "DFS " << endl;

    for (auto x : ans) {
        for (auto i : x) {
            cout << i << " -> ";
        }
    }

    return 0;
}
