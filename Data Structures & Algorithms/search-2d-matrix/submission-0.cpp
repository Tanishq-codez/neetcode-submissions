class Solution {
public:
   
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int x = -1 ; 
        
        int s = 0 ; 
        int e = r-1 ; 
        while(s<=e){
        int  m =  s + (e-s)/2 ;
        if ( target >= matrix[m][0] && target <= matrix[m][c-1])
        {   x = m ;
            break ;  }
        
        else if ( target <  matrix[m][0] )
            e = m -1 ; 

        else if ( target > matrix[m][c-1])
            s = m +1 ; 
        }

        if( x == -1 ) return false ; 
        
        s = 0 ; 
        e = c-1 ; 
        int y = -1 ;
        while (s<=e){
          int  m = s + (e-s)/2 ; 

            if (target == matrix[x][m]) {
            y = m ; 
            break ; 
            } 

            else if ( target < matrix[x][m]) e = m -1 ; 

            else s = m +1 ; 
        }
        if(y!= -1 ) return true ; 
        return false ;

    }
};
