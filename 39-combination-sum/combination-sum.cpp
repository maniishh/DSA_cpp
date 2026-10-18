class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    void solve(int idx, vector<int>& nums, int target) {
        if (idx == nums.size() || target < 0)
            return;
        if (target == 0) {
            ans.push_back(res);
            return;
        }
        res.push_back(nums[idx]);
        solve(idx, nums, target - nums[idx]);
        res.pop_back();

        solve(idx + 1, nums, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 2,3,6,7
        // 2 2 3
        solve(0, candidates, target);
        return ans;
    }
};