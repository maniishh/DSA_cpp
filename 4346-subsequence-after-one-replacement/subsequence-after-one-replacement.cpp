class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        
        vector<int> pref(n, -1), suf(n, -1);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i])
                j++;
            if (j < m) {
                pref[i] = j;
                j++;
            } else
                break;
        }
        if (pref[n - 1] != -1)
            return true;

        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i])
                j--;
            if (j >= 0) {
                suf[i] = j;
                j--;
            } else
                break;
        }
        for (int i = 0; i < n; i++) {
            int left = -1;
            int right = m;

            if (i > 0) {
                if (pref[i - 1] == -1)
                    continue;
                left = pref[i - 1];
            }

            if (i < n - 1) {
                if (suf[i + 1] == -1)
                    continue;
                right = suf[i + 1];
            }
            if (left < right - 1)
                return true;
        }
        return false;
    }
    };