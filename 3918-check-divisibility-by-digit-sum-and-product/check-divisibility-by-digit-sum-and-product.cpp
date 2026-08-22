class Solution {
public:
    int f(int num) {
        int sum = 0, prod = 1;
        while (num > 0) {
            sum += num % 10;
            prod *= num % 10;
            num /= 10;
        }
        return sum + prod;
    }
    bool checkDivisibility(int n) { return n % f(n) == 0; }
};