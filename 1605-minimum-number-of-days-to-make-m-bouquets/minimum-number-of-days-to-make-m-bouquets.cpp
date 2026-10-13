class Solution {
private:
    bool check(int mid, vector<int>& bl, int m, int k) {
        int cnt = 0;
        int bq = 0;
        for (int i = 0; i < bl.size(); i++) {
            if (bl[i] <= mid) {
                cnt++;
                if (cnt == k) {
                    bq++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return bq >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, bloomDay, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};