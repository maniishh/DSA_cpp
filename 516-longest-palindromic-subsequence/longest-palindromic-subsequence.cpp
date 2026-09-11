class Solution {
public:
    int f(string& s, int low, int high, vector<vector<int>>& dp) {
        if (low > high)
            return 0;
        if (low == high)
            return 1;
        if (dp[low][high] != -1)
            return dp[low][high];
        if (s[low] == s[high])
            return dp[low][high] = f(s, low + 1, high - 1, dp) + 2;
        else
            return dp[low][high] =
                       max(f(s, low + 1, high, dp), f(s, low, high - 1, dp));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return f(s, 0, s.size() - 1, dp);
    }
};