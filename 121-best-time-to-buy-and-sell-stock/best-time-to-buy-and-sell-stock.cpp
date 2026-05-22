class Solution {
public:
 int maxProfit( vector<int>& prices) {
    int mp = 0;
    int mnp = prices[0];
 for(int i=1; i<prices.size(); i++) {
       int cost=prices[i]-mnp;
        mp = max(mp, cost);
        mnp = min(mnp, prices[i]);
 }
    return mp;
}
 
};