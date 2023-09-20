#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;
// fot generac input 
template <typename T>

/* we building matrix using list 
    there is only sorting problem -> list will add node in given sequence 
    
    if we use set it will store node in increasing order 
    

    tc => O(n + m)
    sc => O(n + m)
*/


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

    void bfs(unordered_map<int, bool> &visited, vector<int> &ans, int node)
    {
        // create queue
        queue<int> q;
        q.push(node);

        visited[node] = 1;

        while(!q.empty()){

            int frontNode = q.front();
            q.pop();

            // store data in ans
            ans.push_back(frontNode);
            
            // push all conneting node's

            for(auto x : adj[frontNode]){
                if(!visited[x]){
                    visited[x] = 1;
                    q.push(x);
                }
            } 
        }
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

    unordered_map<int,bool> visited;
    vector<int> ans;
    for(int i=0; i<n; i++)
    {
        if(!visited[i]){
            g.bfs(visited, ans, i);
        }
    }

    cout << "BFS " << endl;

    for(auto x : ans){
        cout << x << " -> ";
    }






    return 0;
}