// Last updated: 01/04/2026, 19:26:31
class Solution {
    public:
    int n;
    vector<int>coin; 
    int dp[301][5001];
    int rec(int l,int s){
        if(s < 0) return 0;
        if(l == n){
            if(s==0) return 1;
            else return 0;
        }
        if(dp[l][s] != -1) return dp[l][s];
        return dp[l][s] = rec(l+1,s) + rec(l,s-coin[l]);
    }
public:
    int change(int amount, vector<int>& coins) {
       n = coins.size();
       coin = coins;
       memset(dp,-1,sizeof(dp));
       return rec(0,amount);
    }
};