class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int t = 0;
        for (int i = 0; i < nums.size(); i++) {
            t += mx - nums[i];
        }
        return t;
    }
};