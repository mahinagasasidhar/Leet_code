// Last updated: 01/04/2026, 19:24:07
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long total = accumulate(cost.begin(),cost.end(),0LL);
        int n = s.size();
        vector<long long> ans(256,0);
        long long maxcost = 0;
        for(int i=0;i<n;i++){
            ans[s[i]] += cost[i];
            maxcost = max(maxcost,ans[s[i]]);
        }
        return total-maxcost;
    }
};