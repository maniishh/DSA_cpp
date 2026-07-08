class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int oddCount = 0;
        int ans = 0;

        for (int num : nums) {
            if (num % 2)
                oddCount++;

            if (mp.count(oddCount - k))
                ans += mp[oddCount - k];

            mp[oddCount]++;
        }

        return ans;
    }
};