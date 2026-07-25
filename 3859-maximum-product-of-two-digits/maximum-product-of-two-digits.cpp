class Solution {
public:
    int maxProduct(int n) {
        vector<int> freq(10, 0);

        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }

        int first = -1, second = -1;

        for (int d = 9; d >= 0; d--) {
            if (freq[d] > 0) {
                if (freq[d] >= 2)
                    return d * d;
                first = d;
                break;
            }
        }

        for (int d = first - 1; d >= 0; d--) {
            if (freq[d] > 0) {
                second = d;
                break;
            }
        }

        return first * second;
    }
};