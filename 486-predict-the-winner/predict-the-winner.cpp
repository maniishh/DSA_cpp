class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int tl = nums[i] +
                 min(solve(i + 1, j - 1, nums, dp), solve(i + 2, j, nums, dp));
        int tr = nums[j] +
                 min(solve(i + 1, j - 1, nums, dp), solve(i, j - 2, nums, dp));

        return dp[i][j] = max(tl, tr);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += nums[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        int p1 = solve(0, n - 1, nums, dp);
        int p2 = ans - p1;
        return p1 >= p2;
    }
};