class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n < 2)
            return s;

        int maxlen = 1;
        int st = 0;

        for (int i = 0; i < n; i++) {

            int l = i - 1, r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;

                if (len > maxlen) {
                    maxlen = len;
                    st = l;
                }

                l--;
                r++;
            }

            int left = i, right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;

                if (len > maxlen) {
                    maxlen = len;
                    st = left;
                }

                left--;
                right++;
            }
        }

        return s.substr(st, maxlen);
    }
};