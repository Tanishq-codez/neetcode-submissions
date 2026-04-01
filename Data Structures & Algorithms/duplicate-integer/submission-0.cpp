class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int  , int > map ;
        for (int i = 0 ; i < nums.size() ; i++){
            int key = nums[i];
            if ( map[key] != 1){
                map[key] = 1 ;
            }
            else return true;
        }
        return false ; 
    }
};