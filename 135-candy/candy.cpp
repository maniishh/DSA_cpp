class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> cand(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i - 1] < ratings[i]) {
                cand[i] = cand[i - 1] + 1;
            }  
        }
         for (int i = n-2; i>=0; i--) {
            if (ratings[i + 1] < ratings[i]) {
                cand[i]=max(cand[i],cand[i+1]+1);
            }  
        }

        int tc = accumulate(cand.begin(), cand.end(), 0);
        return tc;
    }
};