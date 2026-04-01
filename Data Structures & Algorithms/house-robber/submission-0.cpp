class Solution {
public:
   int maxAmnt ( vector <int> & nums , int s  , vector<int> &done){

    if( s<= 0 ) return 0 ;

    if ( done[s] == -1 ){
    return done[s] =  max( nums[s-1] + maxAmnt ( nums , s-2 , done   ) , maxAmnt( nums , s-1 , done )  );  }
    
    else return done[s] ;
   }

    int rob(vector<int>& nums) {
    
    int s = nums.size();
    vector <int > done ( s+1 , -1);
    return maxAmnt( nums , s , done ) ; 
    
    }
};