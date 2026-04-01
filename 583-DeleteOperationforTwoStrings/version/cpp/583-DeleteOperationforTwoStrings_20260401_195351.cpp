// Last updated: 01/04/2026, 19:53:51
1class Solution {
2public:
3    int minDistance(string word1, string word2) {
4        int n = word1.size();
5        int m = word2.size();
6        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
7        for(int i=n-1;i>=0;i--){
8            for(int j=m-1;j>=0;j--){
9                if(word1[i] == word2[j]) dp[i][j] = 1 + dp[i+1][j+1];
10                else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
11            }
12        }
13        return n + m - 2*dp[0][0];
14    }
15};