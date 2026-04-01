// Last updated: 01/04/2026, 19:26:01
class Solution {
public:
    int MOD = 1e9 + 7;
    int rec(int i,int n,int p,vector<int>& group, vector<int>& profit,int minprofit,vector<vector<vector<int>>>& dp){
        if(dp[i][n][p] != -1) return dp[i][n][p];
        if(i == 0){
            int ways = 0;
            if(group[0] <= n && (p+profit[0] >= minprofit)) ways++;
            if(p >= minprofit) ways++;
            return ways%MOD;
        }
        long long ways = 0;
        ways = (ways + rec(i-1,n,p,group,profit,minprofit,dp))%MOD;
        if(group[i] <= n) ways = (ways + rec(i-1,n-group[i],min(minprofit,p+profit[i]),group,profit,minprofit,dp))%MOD;
        return dp[i][n][p] = ways;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int size = group.size();
        vector<vector<vector<int>>> dp(size,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return rec(size-1,n,0,group,profit,minProfit,dp)%MOD;
    }
};