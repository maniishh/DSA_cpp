class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> rh(n, 0);
        int rm = 0;
        int i = n - 1;
        int j = m - 1;
        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                rm++;
                j--;
            }
            rh[i] = rm;
            i--;
        }
        vector<int> ans;
        bool flag = true;
        i = 0;
        j = 0;
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (flag == true && i + 1 < n && rh[i + 1] >= m - j - 1) {
                ans.push_back(i);
                j++;
                flag = false;
            }

            i++;
        }
        return j == m ? ans : vector<int>();
    }
};