class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = nums.size();
        for ( int i = 0 , j = 0 ; i < nums.size() ; i++){
        if ( nums[i] == val) ans-- ; 
        
        else {
            nums[j] = nums[i];
            j++ ; 
        }
        }
        return ans ; 
    }
};