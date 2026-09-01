// class Solution {
// public:
//    int numDistinct(string s, string t) {
//     int n = s.size();
//     int m = t.size();
//     vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

//     for (int i = 0; i <= n; i++) {
//         dp[i][0] = 1;
//     }

//     for (int ind1 = 1; ind1 <= n; ind1++) {
//         for (int ind2 = 1; ind2 <= m; ind2++) {
//             if (s[ind1 - 1] == t[ind2 - 1]) {
//                 dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1] + dp[ind1 - 1][ind2];
//             } else {
//                 dp[ind1][ind2] = dp[ind1 - 1][ind2];
//             }
//         }
//     }

//     return dp[n][m];
// }
// };
class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = solve(i + 1, j + 1, s, t, dp) +
                              solve(i + 1, j, s, t, dp);
        }
        return dp[i][j] = solve(i + 1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, s, t, dp);
    }
};