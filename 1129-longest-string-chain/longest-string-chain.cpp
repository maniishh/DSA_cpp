class Solution {
public:
    static bool comp(string& s1, string& s2) { return s1.size() < s2.size(); }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi = 1;
        vector<int> dp(n + 1, 1);
        sort(words.begin(), words.end(), comp);
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (check(words[i], words[prev]) && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size() + 1)
            return false;
        int f = 0, r = 0;
        while (f < s1.size()) {
            if (r < s2.size() && s1[f] == s2[r]) {
                f++;
                r++;
            } else {
                f++;
            }
        }
        if (f == s1.size() && r == s2.size())
            return true;
        return false;
    }
};