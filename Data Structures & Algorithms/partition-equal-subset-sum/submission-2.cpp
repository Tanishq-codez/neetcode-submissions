class Solution {
public:
    bool helper( int n ,int rem , vector<vector<int>>&dp , vector<int>&nums ){
        if(rem == 0 ) return true ; 
        if(n == 0)return false ; 
        if(dp[n][rem]!=-1) return dp[n][rem];
        
        if (nums[n-1]>rem) return dp[n][rem] = helper(n-1, rem , dp , nums ) ;
        else  return dp[n][rem] = helper(n-1,rem-nums[n-1],dp,nums)||helper(n-1, rem , dp , nums );
    }
    bool canPartition(vector<int>& nums) {
        int sum  = 0 ; 
        for (int i = 0; i < nums.size() ; i++){
        sum+=nums[i];
        }
        if(sum%2 != 0) return false ; 
        int target = sum/2 ;

        vector<vector<int>> dp( nums.size()+1 , vector<int>(target+1,-1)) ;
        return helper ( nums.size() , target ,  dp , nums );
    }
};
