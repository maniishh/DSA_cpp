class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, mini = INT_MAX;
        int mxIdx = 0, mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                minIdx = i;
            }
            if (nums[i] > mx) {
                mx = nums[i];
                mxIdx = i;
            }
        }
        int left = min(minIdx, mxIdx);
        int right = max(minIdx, mxIdx);
        int front = right + 1;
        int back = n - left;

        int both = (left + 1) + (n - right);

        return min({front, back, both});
    }
};