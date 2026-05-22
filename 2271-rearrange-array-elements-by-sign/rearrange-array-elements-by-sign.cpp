class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>a,b,ans;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }
    for(int i=0;i<n/2;i++){
        ans.push_back(a[i]);
        ans.push_back(b[i]);
    }
    return ans;
    }
};