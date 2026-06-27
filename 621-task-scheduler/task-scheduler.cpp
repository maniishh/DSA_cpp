class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        int mx = *max_element(freq.begin(), freq.end());

        int countMax = 0;
        for (int f : freq) {
            if (f == mx)
                countMax++;
        }

        int slots = (mx - 1) * (n + 1) + countMax;

        return max((int)tasks.size(), slots);
    }
};