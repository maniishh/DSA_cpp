class Solution {
public:
    vector<string> res;
    bool valid(string& s) {
        int dep = 0;
        for (char& c : s) {
            if (c == '(') {
                dep++;
            } else {
                dep--;
                if(dep<0) return false;
            }
        }
        return dep == 0;
    }
    void solve(string& curr, int n) {
        if (curr.size() == 2 * n) {
            if (valid(curr)) {
                res.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, n);
        return res;
    }
};