class Solution {
public:
    void solve(int idx, vector<int>& can, int target, vector<vector<int>>& res,
               vector<int>& ans) {
        int n = can.size();
        if (idx == n) {
            if (target == 0) {
                res.push_back(ans);
            }
            return;
        }
        if (can[idx] <= target) {
            ans.push_back(can[idx]);
            solve(idx, can, target - can[idx], res, ans);
            ans.pop_back();
        }
        solve(idx + 1, can, target, res, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        solve(0, candidates, target, res, ans);
        return res;
    }
};