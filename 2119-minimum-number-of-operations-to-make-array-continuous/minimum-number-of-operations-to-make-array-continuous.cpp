class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m = nums.size();
        int left = 0;
        int maxKeep = 0;
        for (int right = 0; right < m; right++) {

            while (nums[right] - nums[left] > n - 1) {
                left++;
            }
            maxKeep = max(maxKeep, right - left + 1);
        }

        return n - maxKeep;
    }
};