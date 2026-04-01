class Solution {
public:
    void dfs (int i , int j , vector<vector<char>>& grid , vector<vector<bool>>&visited  ){
        int r = grid.size();
       int c = grid[0].size();
        if (i < 0 || j < 0 || i >= r || j >= c) return;
        if (grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = true ; 
        dfs(i-1 , j , grid , visited); // up
dfs(i , j-1 , grid , visited); // left
        dfs (i+1 , j , grid , visited);
        dfs (i , j+1 , grid , visited);
    }
    int numIslands(vector<vector<char>>& grid) {
       int r = grid.size();
       int c = grid[0].size();
       vector<vector<bool>>visited(r , vector<bool>(c,false)) ; 
       int n = 0 ; 
       for(int i = 0 ; i < r ; i++  ){
        for(int j = 0 ; j < c ; j++){
            if (!visited[i][j] && grid[i][j] == '1')
           { dfs(i , j ,  grid  , visited  ) ; 
           n++ ; 
           }
          }
          
       }
        return n ;
    }
};
