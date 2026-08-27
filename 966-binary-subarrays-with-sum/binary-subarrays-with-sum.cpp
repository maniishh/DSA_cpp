class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        int cnt = 0, sum = 0;

        mp[0] = 1;

        for (int x : nums) {
            sum += x;

            if (mp.find(sum - goal) != mp.end()) {
                cnt += mp[sum - goal];
            }

            mp[sum]++;
        }

        return cnt;
    }
};