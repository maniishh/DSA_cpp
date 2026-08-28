class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.size();
        int m = s.size();
        if (n > m)
            return "";
        unordered_map<char, int> mp;
        for (char ch : t) {
            mp[ch]++;
        }
        int l = 0, si = 0, cnt = 0, mini = INT_MAX;
        for (int r = 0; r < m; r++) {
            mp[s[r]]--;
            if (mp[s[r]] >= 0) {
                cnt++;
            }
            while (cnt == n) {
                if (r - l + 1 < mini) {
                    mini = min(mini, r - l + 1);
                    si = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
        }
        if (mini == INT_MAX)
            return "";
        return s.substr(si, mini);
    }
};