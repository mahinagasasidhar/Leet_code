// Last updated: 02/04/2026, 21:31:33
1class Solution {
2public:
3    int n,m;
4    int dp[102][102];
5    int rec(int i,int j,string& s1,string& s2,string& s3){
6        if(i == n && j == m) return 1;
7        if(dp[i][j] != -1) return dp[i][j];
8        int ways = 0;
9        if(i < n && s1[i] == s3[i+j]) ways |= rec(i+1,j,s1,s2,s3);
10        if(j < m && s2[j] == s3[i+j]) ways |= rec(i,j+1,s1,s2,s3);
11        return dp[i][j] = ways;
12    }
13    bool isInterleave(string s1, string s2, string s3) {
14        n = s1.size();
15        m = s2.size();
16        if(n + m != s3.size()) return 0;
17        memset(dp,-1,sizeof(dp));
18        return rec(0,0,s1,s2,s3);
19    }
20};