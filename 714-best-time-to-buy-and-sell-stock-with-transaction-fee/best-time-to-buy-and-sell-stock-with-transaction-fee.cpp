class Solution {
public:
    int solve(int i, int buy, vector<int>& p, vector<vector<int>>&dp, int fee) {
        if (i == p.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy) {
            profit = max(-p[i] + solve(i + 1, 0, p, dp, fee),
                         solve(i + 1, 1, p, dp, fee));
        } else {
            profit = max(p[i] - fee + solve(i + 1, 1, p, dp, fee),
                         solve(i + 1, 0, p, dp, fee));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        return solve(0, 1, prices, dp, fee);
    }
};