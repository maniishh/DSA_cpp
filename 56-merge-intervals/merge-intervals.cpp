class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            if (!ans.empty() && ans.back()[1] >= intervals[i][0]) {
                int mx = max(ans.back()[1], intervals[i][1]);
                int st = ans.back()[0];
                ans.pop_back();
                ans.push_back({st, mx});
            } else {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return ans;
    }
};