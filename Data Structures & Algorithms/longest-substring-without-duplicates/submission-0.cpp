class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp ; 
        int maxi = 0 ; 
        
        for(int i = 0 , j= 0; i<s.size() ; i ++ ){
          
          int e = s[i];
          mp[e]++ ; 
          while(mp[e]>1){
                int x = s[j];
                mp[x]-- ; 
                j++ ;
            
          }

          if (1+i-j>maxi) maxi=1+i-j ;  
        }

        return maxi ; 
    }
};
