class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int mo = INT_MAX;
        int me = INT_MAX;
        int oc = 0, ec = 0;
        for (int x : nums1) {
            if (x % 2) {
                oc++;
                mo = min(mo, x);
            } else {
                ec++;
                me = min(me, x);
            }
        }
        bool canE = true;
        for (int x : nums1) {
            if (x % 2) {
                if (x == mo) {
                    canE = false;
                    break;
                }
            }
        }

        bool canO = true;
        for (int x : nums1) {
            if (x % 2 == 0) {
                if (mo >= x) {
                    canO = false;
                    break;
                }
            }
        }
        return canE || canO;
    }
};