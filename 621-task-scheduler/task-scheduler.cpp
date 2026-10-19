class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }
        priority_queue<int> pq;
        queue<pair<int, int>> q; // available fre, time avail
        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }
        int time = 0;
        while (!pq.empty() || !q.empty()) {
            time++;
            if (q.front().second <= time && !q.empty()) {
                pq.push(q.front().first);
                q.pop();
            }
            if (!pq.empty()) {
                int rem = pq.top();
                pq.pop();
                rem--;
                if (rem > 0) {
                    q.push({rem, time + n + 1});
                }
            }
        }
        return time;

        // for (char ch : tasks) {
        //     freq[ch - 'A']++;
        // }

        // int mx = *max_element(freq.begin(), freq.end());

        // int countMax = 0;
        // for (int f : freq) {
        //     if (f == mx)
        //         countMax++;
        // }

        // int slots = (mx - 1) * (n + 1) + countMax;

        // return max((int)tasks.size(), slots);
    }
};