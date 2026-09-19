class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> res;
        for (int i = 0; i < speed.size(); i++) {
            double t = (double)(target - position[i]) / speed[i];
            res.push_back({position[i], t});
        }
        sort(res.begin(), res.end(),
             [](auto& a, auto& b) { return a.first > b.first; });
        int fleetcnt = 0;
        double mxtime = 0;
        for (auto& it : res) {
            double time = it.second;
            if (time > mxtime) {
                fleetcnt++;
                mxtime = time;
            }
        }
        return fleetcnt;
    }
};