class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int als = 0;
        int bobs = 0;
        int n = piles.size();
        int l = 0, r = n - 1;
        bool turn = false;
        while (l < r) {
            if (piles[r] >= piles[l] && turn == false) {
                als += piles[r];
                r--;
                turn = true;
            } else if (piles[l] >= piles[r] && turn == false) {
                als += piles[l];
                l++;
                turn = true;
            } else if (piles[l] >= piles[r] && turn == true) {
                bobs += piles[r];
                r--;
                turn = false;
            } else if (piles[r] >= piles[l] && turn == true) {
                bobs += piles[l];
                l++;
                turn = false;
            }
        }
        return als > bobs;
    }
};