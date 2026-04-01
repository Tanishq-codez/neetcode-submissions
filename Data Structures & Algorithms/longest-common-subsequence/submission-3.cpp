class Solution {
public:

    int lcs (string t , string s , vector<vector<int>> &v, int i , int j ){
        if( i== 0 || j== 0 ) return 0 ; 
        if ( v[i][j] != -1 ) return v[i][j];

        if(t[i-1] == s[j-1]) return v[i][j] = 1 + lcs(t,s,v,i-1,j-1);

        else  return v[i][j] = max(lcs(t,s,v,i-1,j) , lcs(t,s,v,i,j-1));
    }
    int longestCommonSubsequence(string t, string s) {
        int i = t.size();
        int j = s.size();
        vector<vector<int>> v( i+1 , vector<int>(j+1 , -1) );
        return lcs(t,s,v,i,j);
    }
};
