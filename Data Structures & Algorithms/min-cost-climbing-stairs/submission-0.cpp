class Solution {
public:

    int minCost(vector<int>& cost, int n, vector<int>& dp) {
        if (n == 0) return cost[0];
        if (n == 1) return cost[1];

        if (dp[n] != -1) return dp[n];

        return dp[n] = min(
            minCost(cost, n - 1, dp),
            minCost(cost, n - 2, dp)
        ) + cost[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n, -1);

        return min(
            minCost(cost, n - 1, dp),
            minCost(cost, n - 2, dp)
        );
    }
};