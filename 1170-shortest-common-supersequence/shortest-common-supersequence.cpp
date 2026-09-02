// class Solution {
// public:
//     int solve(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
//         if (i < 0)
//             return j + 1;
//         if (j < 0)
//             return i + 1;
//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s1[i] == s2[j])
//             return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);

//         else
//             return dp[i][j] = 1 + min(solve(i - 1, j, s1, s2, dp),
//                                       solve(i, j - 1, s1, s2, dp));
//     }
//     string shortestCommonSupersequence(string str1, string str2) {
//         int n = str1.size();
//         int m = str2.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//         solve(n - 1, m - 1, str1, str2, dp);
//         string res = "";
//         int i = n - 1, j = m - 1;
//         while (i >= 0 && j >= 0) {
//             if (str1[i] == str2[j]) {
//                 res += str1[i];
//                 i--;
//                 j--;
//             } else if (solve(i - 1, j, str1, str2, dp) <
//                        solve(i, j - 1, str1, str2, dp)) {
//                 res += str1[i];
//                 i--;
//             } else {
//                 res += str2[j];
//                 j--;
//             }
//         }
//         while (i >= 0) {
//             res += str1[i];
//             i--;
//         }
//         while (j >= 0) {
//             res += str2[j];
//             j--;
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;

        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

    
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string ans;
        int i = n, j = m;

        while (i > 0 && j > 0) {

            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                ans += s1[i - 1];
                i--;
            } else {
                ans += s2[j - 1];
                j--;
            }
        }

        while (i > 0)
            ans += s1[--i];

        while (j > 0)
            ans += s2[--j];

        reverse(ans.begin(), ans.end());

        return ans;
    }
};