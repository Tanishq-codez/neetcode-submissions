class Solution {
public:
    int mySqrt(int x) {
        int s = 0 ;
        int e = x ;
        int m ;
        int res = 0 ; 
        while ( s <= e){
            m = s + (e-s)/2 ;
            if ((long long) m*m == x)return m ; 
            if ((long long) m*m < x ){
                res = m ;
                s = m + 1 ;
            }

            else e = m - 1; 
        }

        return res ; 
    }
};