class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        string an = "";
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        vector<pair<int, char>> ans;
        for (auto it : mp) {
            ans.push_back({it.second, it.first});
        }
        sort(ans.begin(), ans.end(),
             [](const pair<int, char>& a, const pair<int, char>& b) {
                 return a.first > b.first;
             });
        for (auto it : ans) {
            for (int i = 0; i < it.first; i++) {
                an += it.second;
            }
        }

        return an;
    }
};