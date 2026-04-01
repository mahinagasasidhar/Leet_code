// Last updated: 01/04/2026, 19:25:33
class Solution {
public:
    int MOD = 1e9 + 7;
    /*long long rec(int i,int target,int k,vector<vector<long long>>& dp){
        if(i == 0){
            if(target == 0) return 1;
            else return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        long long ways = 0;
        for(int j=1;j<=k;j++) {
            if(target >= j) ways = (ways + rec(i-1,target-j,k,dp))%MOD;
        }
        return dp[i][target] = ways%MOD;
    }*/
    int numRollsToTarget(int n, int k, int target) {
        vector<long long> dp(target+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=target;j>=0;j--){
                long long ways = 0;
                for(int x = 1;x<=k;x++){
                    if(j >= x) ways = (ways + dp[j-x])%MOD;
                }
                dp[j] = ways;
            }
        }
        return dp[target]%MOD;
    }
};