class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minp=prices[0];
       int minc=0;
       int mx=0;
       for(int i=1;i<prices.size();i++){
          minc=max(minc,prices[i]-minp);
          minp=min(prices[i],minp);
          mx=max(mx,minc);
       } 
       return mx;
    }
};