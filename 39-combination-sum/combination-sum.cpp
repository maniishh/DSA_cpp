class Solution {
public:
    vector<vector<int>> res;
    void solve(int idx, vector<int>& can, int target, vector<int>& ans) {
        if (target == 0) {
            res.push_back(ans);
            return;
        }
        if (target < 0 || idx == can.size())
            return;

        ans.push_back(can[idx]);
        solve(idx, can, target - can[idx], ans);
        ans.pop_back();
        solve(idx + 1, can, target, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        solve(0, candidates, target, ans);
        return res;
    }
};