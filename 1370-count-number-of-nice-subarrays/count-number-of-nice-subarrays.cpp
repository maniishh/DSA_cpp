class Solution {
public:
    int f(vector<int>& nums, int k) {
        int l = 0, cnt = 0, oc = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) {
                oc++;
            }
            while (oc > k) {
                if (nums[l] % 2 != 0) {
                    oc--;
                }
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k - 1);
    }
};