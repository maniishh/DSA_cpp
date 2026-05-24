class Solution {
public:
    long long tame(vector<int>& piles, int x) {
        int n = piles.size();
        long long time = 0;
        for (int i = 0; i < n; i++) {
            time += (piles[i] + x - 1) / x;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int ans = 0;
        int high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (tame(piles, mid) <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};