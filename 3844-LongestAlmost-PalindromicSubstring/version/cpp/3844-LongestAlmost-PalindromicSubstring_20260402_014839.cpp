// Last updated: 02/04/2026, 01:48:39
1class Solution {
2public:
3    vector<vector<int>> dp;
4    int rec(int i,int j,string& s){
5        if(i >= j) return 0;
6        if(dp[i][j] != -1) return dp[i][j];
7        if(s[i] == s[j]) return dp[i][j] = rec(i+1,j-1,s);
8        return dp[i][j] = 1+min(rec(i+1,j,s),rec(i,j-1,s));
9    }
10    int almostPalindromic(string s) {
11        int n = s.size();
12        dp.assign(n,vector<int>(n,-1));
13        int ans = 1;
14        for(int i=0;i<n;i++){
15            for(int j=i;j<n;j++){
16                if(rec(i,j,s) <= 1) ans = max(ans,j-i+1);
17            }
18        }
19        return ans;
20    }
21};