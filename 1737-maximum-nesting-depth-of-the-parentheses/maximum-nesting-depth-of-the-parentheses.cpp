class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxd = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
                maxd = max(maxd, depth);
            } else if (s[i] == ')') {
                depth--;
            }
        }
        return maxd;
    }
};