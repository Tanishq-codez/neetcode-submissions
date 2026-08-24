class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(
            solve(0, n - 1, nums, dp1),
            solve(1, n, nums, dp2)
        );
    }

private:
    int solve(int i, int end, vector<int>& nums, vector<int>& dp) {
        if (i >= end)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = max(
            solve(i + 1, end, nums, dp),
            nums[i] + solve(i + 2, end, nums, dp)
        );
    }
};