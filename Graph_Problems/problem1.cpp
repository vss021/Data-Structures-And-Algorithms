#include <bits/stdc++.h>


using namespace std;

class Solution {
    /*
    This Solution two Approaches 
        -> BFS Method 
                 initially sare Nodes ka distance INFINITE rakhege (Dist[src]=0).  
                 Normal BFS perform karege, jab bhi kisi Node ka newDistance (distance[node] + dist)  ,
                 uske currDistance (distance[nbr]) se kam hoga to ham  node ka distance update kr dege, 
                 aur CurrNode ko Queue me push kar dege kyuki ho skta he currNode ke distance updation 
                 se other nodes ke distance par effect padega.
    */
    
    vector<int> solveUsingBFS(int N, vector<vector<pair<int, int>>>& adj) {
        
        vector<int> distance(N, INT_MAX);
    
        distance[0] = 0;
    
        queue<int> q;
        q.push(0);
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
    
            for (auto& neighbor : adj[node]) {
                int next = neighbor.first;
                int dist = neighbor.second;
    
                if (distance[node] + dist < distance[next]) {
                    distance[next] = distance[node] + dist;
                    q.push(next);
                }
            }
        }
    
        for (auto& d : distance) {
            if (d == INT_MAX)
                d = -1;
        }
    
        return distance;
    }
    
    /*
    Basicallly in this approach ham jab bhi kisi Node ka distance undate kar rhe he uss Node ko Queue me dal rhe he.
    already processed node ko baar baar Queue me daal rhe he, for this Time Complexity is little bit 
    expensive than Effiecient Approach.
    */

    /*
    Approach 2.
        So What can we do now?? so that we process each note only one time ??

Hint :Given graph is DAG.

         DAG me ham vertices ka topological order find karte he jo hame batata he ki node 
         (u) hmesha node (v) ke phle aayegi.
         
         Why Topological Sort : 
         In previous approach source(u) se kisi node(v) tak 
         pahuchane ke multiple paths ho skte he par optimal path konsa hoga, ye nhi 
        pata....  
        isliye ham saare paths se cost nikal rhe the aur optimal cost update 
        kar rhe the. So agar hme ye pata chal jaye ki node(u) se node(v) tak jane ke 
        jitne bhi paths he wo paths ke sare nodes agar ham node(v) tak pahuchne se 
        pahle hi mil jaye so that ham node(v) jab par pahuchege to sare paths ke 
        nodes ka process kar chuke ho. To esa order , Topological Sort se milata he.
    
    
    Ham Toposort ka use karege ,
    Toposort se one by one node ko lekar uske adjacent  nodes nodes ka distance update kar dege 
    (If newDistance of adjacent nodes is less than currDistance).

    We are processing every node of the Toposort only one time 
    thats why Time Complexity of this appproach is less than previous approach.
    
    */
    
    // Topo using DFS
    
    vector<int> stak;
    void DFS_Topo_sort(int node, vector<vector<int>> adj[], vector<int> &visited){
        visited[node] = true;
        
        for(auto nbr : adj[node]){
            if(!visited[nbr[0]])
                DFS_Topo_sort(nbr[0], adj, visited);
        }
        stak.push_back(node);
    }
    
  public:
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        
        // Call BFS method
        /*
        vector<vector<pair<int, int>>> adj(N);
    
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
    
        // return solveUsingBFS(N, adj);
        */ 
         
        vector<vector<int>> adj[N];
        
        for(auto e : edges){
            adj[e[0]].push_back( {e[1], e[2]} );
        }
        
        //finding Toposort
        
        vector<int> visited(N), distance(N, INT_MAX) ;
        DFS_Topo_sort( 0, adj , visited) ;
        // reverse(stak.begin() , stak.end()) ;
        
        distance[0] = 0;
        while(stak.size())
        {
            int node = stak.back();
            stak.pop_back() ;
            
            for(auto &nbrData : adj[node]){
                int nbr = nbrData[0] ;
                int wt = nbrData[1] ;
                if(distance[node] + wt < distance[nbr]){
                    distance[nbr] = distance[node] + wt ;
                }
            }
        }
        for(auto &d : distance)
            if(d == INT_MAX)d = -1;
            
        return distance ;
    }
};


int main() {
    int N, M;
    cout << "Enter the number of vertices and edges: ";
    cin >> N >> M;

    vector<vector<int>> edges(M, vector<int>(3));
    cout << "Enter the edges (format: source destination weight):" << endl;
    for (int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    Solution sol;
    vector<int> result = sol.shortestPath(N, M, edges);

    // Print the result
    cout << "Shortest Distances from Node 0: ";
    for (int dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
