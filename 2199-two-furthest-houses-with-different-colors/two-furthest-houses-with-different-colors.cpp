class Solution {
public:
 int maxDistance(vector<int>& colors) {
    int n = colors.size();
    int max_dist = 0;

    // Scan from the right: find farthest house different from colors[0]
    for (int j = n - 1; j > 0; j--) {
        if (colors[j] != colors[0]) {
            max_dist = max(max_dist, j);
            break;
        }
    }

    // Scan from the left: find farthest house different from colors[n-1]
    for (int i = 0; i < n - 1; i++) {
        if (colors[i] != colors[n - 1]) {
            max_dist = max(max_dist, n - 1 - i);
            break;
        }
    }

    return max_dist;
}
};