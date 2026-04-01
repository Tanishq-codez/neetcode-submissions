class Solution {
public:
    void backtrack(vector<int>& nums, int target, int idx,
                   vector<vector<int>>& ans, vector<int>& v) {

        if (target == 0) {
            ans.push_back(v);
            return;
        }

        if (target < 0) return;

        for (int i = idx; i < nums.size(); i++) {
            if(nums[i]==nums[i-1] && i> idx) continue ; 
            v.push_back(nums[i]);                     
            backtrack(nums, target - nums[i], i+1, ans, v); 
            v.pop_back();                            
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin() , nums.end());
        backtrack(nums, target, 0, ans, v);
        return ans;
    }
};