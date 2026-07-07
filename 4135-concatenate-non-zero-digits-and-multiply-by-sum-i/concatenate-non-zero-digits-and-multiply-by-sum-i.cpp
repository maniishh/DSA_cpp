class Solution {
public:
    int removeZeros(int n) {
        int num = 0, place = 1;

        while (n > 0) {
            int dig = n % 10;
            if (dig != 0) {
                num = dig * place + num;
                place *= 10;
            }
            n /= 10;
        }
        return num;
    }

    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    long long sumAndMultiply(int n) {
        int x = removeZeros(n);
        return 1LL * x * digitSum(x);
    }
};
