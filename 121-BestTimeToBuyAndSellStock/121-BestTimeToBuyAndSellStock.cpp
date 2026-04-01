// Last updated: 01/04/2026, 19:28:02
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int p = 0;
    int m = prices[0];
    for(int i = 1;i < n;i++){
        p = max(p,prices[i] - m);
        m = min(m,prices[i]);
    }
    return p;
    }
};