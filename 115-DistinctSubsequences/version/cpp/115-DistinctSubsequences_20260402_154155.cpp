// Last updated: 02/04/2026, 15:41:55
1class Solution {
2public: 
3    int n,m;
4    int rec(int i,int j,string& s,string& t,vector<vector<int>>& dp){
5        if(j == m) return 1;
6        if(i == n) return 0;
7        if(dp[i][j] != -1) return dp[i][j];
8        int ways = rec(i+1,j,s,t,dp);
9        if(s[i] == t[j]) ways += rec(i+1,j+1,s,t,dp);
10        return dp[i][j] = ways;
11
12    }
13    int numDistinct(string s, string t) {
14        n = s.size();
15        m = t.size();
16        vector<vector<int>> dp(n,vector<int>(m,-1));
17        return rec(0,0,s,t,dp);
18    }
19};