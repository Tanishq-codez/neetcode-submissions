class Solution {
public:
    int helper(int i, int p, vector<vector<int>>& dp, vector<int>& nums) {
        if (i < 0) return 0;  // no more elements to consider

        if (dp[i][p] != -1) return dp[i][p];

        // option 1: skip nums[i]
        int skip = helper(i - 1, p, dp, nums);

        // option 2: take nums[i], only valid if no previous chosen (p==n) or nums[i] < nums[p]
        int take = 0;
        if (p == nums.size() || nums[i] < nums[p]) {
            take = 1 + helper(i - 1, i, dp, nums);
        }

        return dp[i][p] = max(skip, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(n - 1, n, dp, nums);
    }
};