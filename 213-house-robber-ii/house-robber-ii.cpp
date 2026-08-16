class Solution {
public:
    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx == 0)
            return nums[idx];

        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int pick = nums[idx] + solve(idx - 2, nums, dp);
        int notpick = solve(idx - 1, nums, dp);

        return dp[idx] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> v1, v2;

        for (int i = 0; i < n; i++) {
            if (i != 0)
                v1.push_back(nums[i]);

            if (i != n - 1)
                v2.push_back(nums[i]);
        }

        vector<int> dp1(v1.size(), -1);
        vector<int> dp2(v2.size(), -1);

        int c1 = solve(v1.size() - 1, v1, dp1);
        int c2 = solve(v2.size() - 1, v2, dp2);

        return max(c1, c2);
    }
};