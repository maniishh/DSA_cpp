class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    void solve(int idx, int k, int n) {
        if (k == 0 && n == 0) {
            res.push_back(ans);
            return;
        }
        if (k == 0 || n < 0) {
            return;
        }
        for (int i = idx; i <= 9; i++) {
            ans.push_back(i);
            solve(i + 1, k - 1, n - i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1, k, n);
        return res;
    }
};