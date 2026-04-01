// Last updated: 01/04/2026, 19:28:36
class Solution {
    int rec(int m,int n,vector<vector<int>>& dp){
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        if(m == 0 && n == 0) return 1;
        int ans = rec(m-1,n,dp) + rec(m,n-1,dp);
        return  dp[m][n] = ans;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i = 0; i < m;i++){
            for(int j = 0;j < n;j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            }
        }
        return rec(m-1,n-1,dp);
    }
};