class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int m = words.size();
        int k = words[0].size();

        unordered_map<string, int> need;
        for (auto& w : words)
            need[w]++;

        for (int start = 0; start < k; start++) {
            unordered_map<string, int> have;
            int left = start;
            int count = 0;

            for (int right = start; right + k <= n; right += k) {
                string word = s.substr(right, k);

                if (need.count(word)) {
                    have[word]++;
                    count++;

                    while (have[word] > need[word]) {
                        string leftWord = s.substr(left, k);
                        have[leftWord]--;
                        left += k;
                        count--;
                    }

                    if (count == m) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, k);
                        have[leftWord]--;
                        left += k;
                        count--;
                    }
                } else {
                    have.clear();
                    count = 0;
                    left = right + k;
                }
            }
        }

        return ans;
    }
};