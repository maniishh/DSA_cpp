class Solution {
public:
    // int solve(int idx, vector<int>& nums, vector<int>& dp) {
    //     if (idx == 0)
    //         return nums[idx];
    //     if (idx < 0)
    //         return 0;
    //     if (dp[idx] != -1)
    //         return dp[idx];
    //     int pick = nums[idx] + solve(idx - 2, nums, dp);
    //     int notpick = solve(idx - 1, nums, dp);
    //     return dp[idx] = max(pick, notpick);
    // }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        // return solve(nums.size() - 1, nums, dp);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int tk=nums[i];
            if(i>1) tk+=dp[i-2];
            int ntk=dp[i-1];

            dp[i]=max(tk,ntk);
        }
        return dp[nums.size()-1];
    }
};