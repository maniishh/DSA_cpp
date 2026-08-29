class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        int grpNum = 0;
        unordered_map<int, int> numToGrp;
        numToGrp[vec[0]] = grpNum;
        unordered_map<int, list<int>> GrpTolist;
        GrpTolist[grpNum].push_back(vec[0]);//O(1)
        for (int i = 1; i < n; i++) {//O(n)
            if (abs(vec[i] - vec[i - 1]) > limit) {
                grpNum++;
            }
            numToGrp[vec[i]] = grpNum;//O(1)
            GrpTolist[grpNum].push_back(vec[i]);
        }
        vector<int> result(n);
        for (int i = 0; i < n; i++) {//O(n)
            int num = nums[i];
            int group = numToGrp[num];
            //smallest available number in this grp..usi ko lenge
            result[i] = *GrpTolist[group].begin();
            GrpTolist[group].pop_front();//use ho gya to delete kr do
        }
        return result;
    }
};