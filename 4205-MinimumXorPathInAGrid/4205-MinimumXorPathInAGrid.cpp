// Last updated: 01/04/2026, 19:23:43
class Solution {
public:
    int n,m;
    int rec(int i,int j,int x,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(i == n-1 && j == m-1){
            return x^grid[i][j];
        }
        if(dp[i][j][x] != -1) return dp[i][j][x];
        int ans = INT_MAX;
        if(i < n-1) ans = rec(i+1,j,x^grid[i][j],grid,dp);
        if(j < m-1) ans = min(rec(i,j+1,x^grid[i][j],grid,dp),ans);
        return dp[i][j][x] = ans;
    }
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size(); 
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));
        return rec(0,0,0,grid,dp);
    }
};