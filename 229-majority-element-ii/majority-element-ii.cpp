class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, v1 = 0;//as boyar moore applied for two candidate becoz there will bwe at max 2 elements
        int cand2 = 0, v2 = 0;
        for (int x : nums) {
            if (x == cand1) {
                v1++;
            } else if (x == cand2) {
                v2++;
            } else if (v1 == 0) {
                cand1 = x;
                v1 = 1;
            } else if (v2 == 0) {
                cand2 = x;
                v2 = 1;
            }
        else{
            v1--;
            v2--;
        }
        }
        v1 = 0, v2 = 0;
        for (int x : nums) {
            if (x == cand1) {
                v1++;
            } else if (x == cand2) {
                v2++;
            }
        }
        vector<int> ans;
        if (v1 > nums.size() / 3)
            ans.push_back(cand1);
        if (v2 > nums.size() / 3)
            ans.push_back(cand2);
        return ans;
    }
};