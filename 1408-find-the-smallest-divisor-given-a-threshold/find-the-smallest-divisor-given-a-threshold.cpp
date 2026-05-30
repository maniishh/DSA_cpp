class Solution {
public:
int f(int x,vector<int>&nums){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=(nums[i]+x-1)/x;
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1,h=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(f(mid,nums)<=threshold){
                ans=mid;
               h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};