class Solution {
public:
    vector<vector<int>> res;
    void solve(int idx, int k, int target, vector<int>& ans) {
        if (k == 0 && target == 0) {
            res.push_back(ans);
            return;
        }
        if (k == 0 || target < 0) {
            return;
        }
        for (int i = idx; i <= 9; i++) {
            ans.push_back(i);
            solve(i + 1, k - 1, target - i, ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        solve(1, k, n, ans);
        return res;
    }
};