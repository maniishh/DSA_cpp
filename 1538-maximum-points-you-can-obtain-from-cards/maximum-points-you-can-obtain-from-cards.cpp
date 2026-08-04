class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        int t = 0;
        for (int x : a)
            t += x;
        if (k == n)
            return t;
        int w = 0;
        for (int i = 0; i < n - k; i++)
            w += a[i];
        int m = w;
        for (int i = n - k; i < n; i++) {
            w += a[i] - a[i - (n - k)];
            m = min(m, w);
        }
        return t - m;
    }
};