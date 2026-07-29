class Solution {
public:
    int components = 0 ; 
    vector<int>visited ;

    int countComponents(int n, vector<vector<int>>& edges) {
     visited.resize(n,0); 
     vector<vector<int>> adj(n) ; 
     for(auto &edge : edges ){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back( edge[0] );
     }
     
     for(int node = 0; node < n; ++node){
        if( !visited[node] ){
            dfs(node,adj);
            components++; 
        }

     }

     return components ; 

    }

    void dfs(int node, vector<vector<int>>adj ){
        visited[node] = true ; 
        for( int n : adj[node]){
            if(!visited[n]){
                dfs(n,adj);
            }
        }
    }
};
