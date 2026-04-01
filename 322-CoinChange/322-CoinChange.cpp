// Last updated: 01/04/2026, 19:26:57
class Solution {
public:
    int dp[13][10001];
    int n;
    vector<int>coin;
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        coin = coins;
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,amount);
        return (ans == 1e7 + 1) ? -1 : ans;
    }
    int rec(int l,int s){
        if(s < 0) return 1e7 + 1;
        if(l == n){
            if(s == 0) return 0;
            else return 1e7 + 1;
        }
        if(dp[l][s] != -1) return dp[l][s];
        long long ans = 1e7 + 1;
        ans = min({(long long)(1 + rec(l,s-coin[l])),(long long)rec(l+1,s),ans});
        return dp[l][s] = ans;
    }
};