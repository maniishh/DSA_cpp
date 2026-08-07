class Solution {
public:
    int dp(int n) {
        int ans = 1;
        while (n > 0) {
            int dig = n % 10;
            ans *= dig;
            n /= 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int dummy = n;
        int ans = n;
        while (dummy >= n) {
            if (dp(dummy) % t == 0) {
                ans = dummy;
                break;
            } else {
                dummy += 1;
            }
        }
        return ans;
    }
};