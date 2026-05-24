class Solution {
public:
    int f(vector<int>& weights, int x) {
        int cap = 0;
        int d = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (cap + weights[i] <= x) {
                cap += weights[i];
            } else {
                d++;
                cap = weights[i];
            }
        }

        return d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += weights[i];
        }
        int high = sum;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (f(weights, mid) <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};