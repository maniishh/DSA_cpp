class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            q.push(i);
        }

        while (!q.empty()) {
            int num = q.front();
            q.pop();
            int ld = num % 10;
            ld = ld + 1;
            if (ld <= 9) {
                int n = num * 10 + ld;
                q.push(n);
            }

            if (num >= low && num <= high) {
                res.push_back(num);
            }
        }
        return res;
    }
};