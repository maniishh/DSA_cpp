class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int ms=nums[0];
        for(int i=1;i<n;i++){
            ms=max(nums[i],ms+nums[i]);
            ans=max(ans,ms);
        }
        return ans;
    }
};