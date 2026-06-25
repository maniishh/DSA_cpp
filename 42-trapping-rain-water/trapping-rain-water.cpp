class Solution {
public:
    vector<int> f1(vector<int>& h, int n) {
        vector<int> lmx(n);
        lmx[0] = h[0];
        for (int i = 1; i < n; i++) {
            lmx[i] = max(lmx[i - 1], h[i]);
        }
        return lmx;
    }
    vector<int> f2(vector<int>& h, int n) {
        vector<int> rmx(n);
        rmx[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmx[i] = max(rmx[i + 1], h[i]);
        }
        return rmx;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lm = f1(height, n);
        vector<int> rm = f2(height, n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int h = min(lm[i], rm[i]) - height[i];
            sum += h;
        }
        return sum;
    }
};