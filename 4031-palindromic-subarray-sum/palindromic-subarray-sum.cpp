class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        auto nalviretho = nums;
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
         auto getSum = [&](int l, int r) { return pref[r + 1] - pref[l]; };

            long long ans = *max_element(nums.begin(), nums.end());
            vector<int> d1(n);
            int l = 0, r = -1;
            for (int i = 0; i < n; i++) {
                int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
                while (i - k >= 0 && i + k < n && nums[i - k] == nums[i + k])
                    k++;
                d1[i] = k--;
                if (i + k > r) {
                    l = i - k;
                    r = i + k;
                }
                int left = i - d1[i] + 1;
                int right = i + d1[i] - 1;
                ans =max(ans, getSum(left, right));
            }
            vector<int> d2(n);
            l = 0, r = -1;
            for (int i = 0; i < n; i++) {
                int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

                while (i - k - 1 >= 0 && i + k < n &&
                       nums[i - k - 1] == nums[i + k])
                    k++;

                d2[i] = k--;

                if (i + k > r) {
                    l = i - k - 1;
                    r = i + k;
                }

                if (d2[i] > 0) {
                    int left = i - d2[i];
                    int right = i + d2[i] - 1;
                    ans = max(ans, getSum(left, right));
                }
            }

            return ans;
        }
    };