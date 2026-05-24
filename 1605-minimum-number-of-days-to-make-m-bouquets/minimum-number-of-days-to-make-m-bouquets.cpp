class Solution {
public:
    bool f(vector<int>& nums, int x, int m, int k) {
        int cnt = 0;
        int y = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= x) {
                cnt++;
            } else {
                y += cnt / k;
                cnt = 0;
            }
        }
        y += cnt / k;
        return m <= y;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        if (1LL * m * k > n)
            return -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (f(bloomDay, mid, m, k) == true) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};