class Solution {
public:
    int f(vector<int>& nums, int start, int end) {
        if (start > end)
            return 0;
        if (start == end)
            return nums[start];

        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++) {
            int current = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int case1 = f(nums, 0, n - 2);

        int case2 = f(nums, 1, n - 1);

        return max(case1, case2);
    }
};