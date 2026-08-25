class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto& x : nums) {
            mp[x]++;
        }
        int ans = 0;
        for (int i = 1; i <= nums.size()+1; i++) {
            if (mp.find(k * i) == mp.end()) {
                ans = k * i;
                break;
            }
            else{
                continue;
            }
        }
        return ans;
    }
};