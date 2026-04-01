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
            v.push_back(nums[i]);                     // choose
            backtrack(nums, target - nums[i], i, ans, v); // reuse allowed
            v.pop_back();                            // undo
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        backtrack(nums, target, 0, ans, v);
        return ans;
    }
};