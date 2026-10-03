class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int negInt = 1, pos = 0;
        vector<int> ans(n);
        for (int x : nums) {
            if (x > 0) {
                ans[pos] = x;
                pos += 2;
            } else {
                ans[negInt] = x;
                negInt += 2;
            }
        }
        return ans;
    }
};