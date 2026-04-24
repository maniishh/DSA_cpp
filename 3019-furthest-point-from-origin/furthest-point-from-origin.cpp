class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0, l = 0;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'R') {
                r++;
            } else if (moves[i] == 'L') {
                l++;
            }
        }
        int mini = min(r, l);
        return moves.size() - 2 * mini;
    }
};