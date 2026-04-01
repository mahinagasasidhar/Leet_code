// Last updated: 01/04/2026, 19:28:34
class Solution {
        int  rec(int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(m == 0 && n == 0) return grid[0][0];
        if(dp[m][n] != -1) return dp[m][n];
        int ans = 1e9;
        if(m>0) ans = min(ans,grid[m][n]+rec(m-1,n,grid,dp));
        if(n>0) ans = min(ans,grid[m][n]+rec(m,n-1,grid,dp));
        return dp[m][n] = ans;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return rec(m-1,n-1,grid,dp);
    }
};