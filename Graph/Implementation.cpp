#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
// fot generac input 
template <typename T>

/*
* => Graph can implement by two types
        -> adjacency Matrix
        -> Adjacency List

* => adjancency Matrix
    -> in this method the nodes are repersenting the row and collumn's
        => 2-D matrix 
        
*   => adjancency List
    -> in this method the each node have there own list where it will store the 
        connected nodes 
        it can we in 
            map<int, vector<int> > 
                    or
            map<int, list<int> > 

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



    return 0;
}