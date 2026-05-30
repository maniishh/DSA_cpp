class Solution {
public:
    string reverseWords(string s) {
        vector<string> st;
        string ans = "";
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                st.push_back(ans);
                ans = "";
            } else {
                ans += s[i];
            }
        }
        st.push_back(ans);
        reverse(st.begin(), st.end());
        for (auto it : st) {
            if (it != "") {
                if (res == "") {
                    res = res + it;
                } else {
                    res = res + " " + it;
                }
            }
        }
        return res;
    }
};