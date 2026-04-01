// Last updated: 01/04/2026, 19:41:48
1class Solution {
2public:
3    int n,m;
4    int rec(int i,int j,string& a,string& b,vector<vector<int>>& dp){
5        if(i == n) return m - j;
6        if(j == m) return n - i;
7        if(dp[i][j] != -1) return dp[i][j];
8        if(a[i] == b[j]) return dp[i][j] = rec(i+1,j+1,a,b,dp);
9        return dp[i][j] = min(1+rec(i+1,j,a,b,dp),1+rec(i,j+1,a,b,dp));
10    }
11    int minDistance(string word1, string word2) {
12        n = word1.size();
13        m = word2.size();
14        vector<vector<int>> dp(n,vector<int>(m,-1));
15        return rec(0,0,word1,word2,dp);
16    }
17};