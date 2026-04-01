// Last updated: 01/04/2026, 19:28:37
class Solution {
    vector<vector<int>> dp;
    int rec(int m,int n){
       if(m < 0 || n < 0) return 0;
       if(m == 0 && n == 0) return 1;
       if(dp[m][n] != -1) return dp[m][n];
       int ans = rec(m-1,n) + rec(m,n-1);
       return dp[m][n] = ans;
    }
public:
    int uniquePaths(int m, int n) {
        dp.assign(m,vector<int>(n,-1));
       return rec(m-1,n-1);
    }
};