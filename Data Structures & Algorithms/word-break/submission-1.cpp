class Solution {
public:
    bool helper ( int i , string s , unordered_map<string,int> mp , vector<int>&dp ){
    
    if( i == s.size() ) return true ; 
    if(dp[i] != -1) return dp[i];
    for( int l = 1 , j = i ; j < s.size() ; l++ ,j++){
    string str = s.substr(i, l) ;
    if (mp[str] == 1) {
    if (helper(i+l, s, mp, dp)) {
        return dp[i] = true;
    }
}
    }
    
    return dp[i] =false ;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp ; 
        for ( int i = 0 ; i <wordDict.size() ;i++){
            string str = wordDict[i] ;
            mp[str]=1 ; 
        }
    
    vector<int> dp(s.size()+1, -1);
    return helper(0,s,mp ,dp) ;
    }
};
