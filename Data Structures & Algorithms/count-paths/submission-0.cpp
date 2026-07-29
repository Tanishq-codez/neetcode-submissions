class Solution {
public:
    vector<vector<int>>v ; 
    int paths(int i , int j  ){
        if( i == 0 && j==0 ) return 1 ; 
        
        if(v[i][j] != -1 ) return v[i][j];
        
        if ( i == 0) return v[i][j] = paths(i,j-1);
        else if ( j == 0) return v[i][j] = paths(i-1,j);
        else return  v[i][j] = paths(i-1 , j) + paths(i,j-1);
    }
    int uniquePaths(int m, int n) {
        v.resize(m , vector<int> (n,-1));
        return paths(m-1,n-1);
        
    }
};
