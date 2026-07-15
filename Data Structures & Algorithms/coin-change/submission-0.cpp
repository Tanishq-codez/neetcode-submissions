class Solution {
   public:
    int helper(int i, vector<vector<int>>& dp, int target, vector<int>& coins) {
        if (target == 0) return 0;

        if (i == -1) return INT_MAX;

        if (dp[i][target] != INT_MAX) return dp[i][target];

        if (coins[i] <= target) {
            int take = INT_MAX;
            int sub = helper(i, dp, target - coins[i], coins);
            if (sub != INT_MAX) take = 1 + sub;

            int skip = helper(i - 1, dp, target, coins);
            return dp[i][target] = min(take, skip);
        }

        else
            return dp[i][target] = helper(i - 1, dp, target, coins);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, INT_MAX));
        int ans = helper(coins.size() - 1, dp, amount, coins);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
