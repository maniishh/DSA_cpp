class Solution {
public:
    const int m = 1e9 + 7;
    int f(long long a, long long b) {
        if (b == 0) {
            return 1;
        }
        long long h = f(a, b / 2);
        long long res = (h * h)%m;
        if (b % 2 == 1) {
            return (res * a)%m;
        }
        return res;
    }
    int countGoodNumbers(long long n) {

        return (long long)f(5, (n + 1) / 2) * f(4, n / 2) % m;
    }
};