class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        for( int i = 1 ; i < nums.size(); i++){
        nums[i] = nums[i]+nums[i-1];
        }
        int ans = 0 ; 
        unordered_map<int , int > mp ;
        for ( int i = 0 ; i < nums.size() ; i ++){
            int comp = nums[i] - k ;
            if ( comp == 0 ) ans++ ; 
            if( mp.find(comp) != mp.end()){
                ans = ans + mp[comp];
            }
            mp[nums[i]]++ ;  
        
        }
        return ans ; 
    }
};