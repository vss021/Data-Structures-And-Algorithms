#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;
// fot generac input 
template <typename T>


class graph{
    public:
    unordered_map<T , list<T> > adj;
    
    void addEduge(int u, int v, bool direction){
        // direction denot's the graph is uni-direction or direction
        // 1 means undirection 
        // 0 means direction 

        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for(auto i: adj)
        {
            cout << i.first << "-->";

            for(auto j : i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }

    bool bfs(unordered_map<int, bool>& visited, int node) {

        unordered_map<int, int> parent;
        parent[node] = -1;

        queue<int> q;

        q.push(node);

        visited[node] = true;

        while (!q.empty()) {

            int currNode = q.front();
            q.pop();

            for (int neighbor : adj[currNode]) {
                
                if (visited[neighbor] && parent[currNode] != neighbor) {
                    return true;
                }

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = currNode;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }

    bool isCycle(int V) {
        unordered_map<int, bool> visited;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bool ans = bfs(visited, i);
                if (ans) {
                    return true;
                }
            }
        }

        return false;
    }

};

int main()
{
    graph<int> g;

    int n;
    cout << "Enter the No. of Nodes " <<endl;
    cin >> n;
    int m;
    cout << "Enter the No. of Eduges " <<endl;
    cin >> m;

    cout << "U and V " << endl;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        // creating undirected graph
        g.addEduge(u, v, 0);

    }

    g.printGraph();

    // Cycle Detection using bfs 
    if(g.isCycle(n)){
        cout << "Cycle is present in the given Graph " << endl;
    }else{
        cout << " No Cycle! " << endl;

    }





    return 0;
}


