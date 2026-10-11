class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1, r = n - 1;
                while (left < r) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[left] + nums[r];
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        r--;
                    } else {
                        vector<int> res = {nums[i], nums[j], nums[left],
                                           nums[r]};
                        sort(res.begin(), res.end());
                        ans.push_back(res);
                        left++;
                        r--;
                        while (r > left && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while (r > left && nums[r] == nums[r + 1]) {
                            r--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};