class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string st = s.substr(i, n) + s.substr(0, i);
            if (st == goal)
                return true;
        }
        return false;
    }
};