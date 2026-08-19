class Solution {
public:
// int f(int ind,int prev,vector<int>&nums,vector<vector<int>>&dp){
//     if(ind==nums.size()) return 0;
//     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
//     int len= f(ind+1,prev,nums,dp);
 
//     if(prev==-1 ||nums[ind]>nums[prev]){
//         len=max(len ,1+f(ind+1,ind,nums,dp));
//     }
//      return dp[ind][prev+1]= len;
   
// }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return f(0,-1,nums,dp);
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(1+dp[prev],dp[i]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};