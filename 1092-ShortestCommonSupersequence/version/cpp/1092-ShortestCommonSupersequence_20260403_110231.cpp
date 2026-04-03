// Last updated: 03/04/2026, 11:02:31
1class Solution {
2public:
3    string shortestCommonSupersequence(string str1, string str2) {
4        int n = str1.size();
5        int m = str2.size();
6        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
7        for(int i=n-1;i>=0;i--){
8            for(int j=m-1;j>=0;j--){
9                if(str1[i] == str2[j]) dp[i][j] = 1 + dp[i+1][j+1];
10                else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
11            }
12        }
13        string ans = "";
14        int i=0,j=0;
15        while(i < n && j < m){
16            if(str1[i] == str2[j]) ans += str1[i],i++,j++;
17            else if(dp[i+1][j] > dp[i][j+1]) ans += str1[i],i++;
18            else ans += str2[j],j++;
19        }
20        while(i < n) ans += str1[i++];
21        while(j < m) ans += str2[j++];
22        return ans;
23    }
24};