// Last updated: 01/04/2026, 19:26:40
class Solution {
public:
    int rec(int i,vector<string>& strs,int a,int b,int m,int n,vector<vector<vector<int>>>& dp){
        if(i == strs.size())  return 0;
        if(dp[i][a][b] != -1) return dp[i][a][b];
        int ans = rec(i+1,strs,a,b,m,n,dp);
        int x = 0;
        int y = 0;
        for(int j=0;j<strs[i].size();j++){
            if(strs[i][j] == '1') y++;
            else x++;
        }
        if(a+x <= m && b+y <= n) ans = max(ans,1 + rec(i+1,strs,a+x,b+y,m,n,dp));
        return dp[i][a][b] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int a = strs.size();
        vector<vector<vector<int>>> dp(a,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return rec(0,strs,0,0,m,n,dp);
    }
};