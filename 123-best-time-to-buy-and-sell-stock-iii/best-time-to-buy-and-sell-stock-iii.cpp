class Solution {
public:
    int solve(int i, int buy, int cap, vector<int>& p,
              vector<vector<vector<int>>>& dp) {
        if (i == p.size() || cap == 0)
            return 0;
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        int profit = 0;
        if (buy) {
            profit = max(-p[i] + solve(i + 1, 0, cap, p, dp),
                         solve(i + 1, 1, cap, p, dp));
        } else {
            profit = max(p[i] + solve(i + 1, 1, cap - 1, p, dp),
                         solve(i + 1, 0, cap, p, dp));
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(3, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};