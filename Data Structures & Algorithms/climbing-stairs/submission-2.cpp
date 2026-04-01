class Solution {
public:
    int count( int n , vector<int> &memo ) {

        
        if ( n == 0 ) return 1 ;
        if (n<0) return 0 ;

        if ( memo[n] != -1) return memo [n] ;

        else 
        return memo[n] =  count( n-1 , memo ) + count(n-2 , memo);
    }
    int climbStairs(int n) {

        vector <int> memo ( n+1 , -1);

        return count ( n , memo );
       
    }
};
