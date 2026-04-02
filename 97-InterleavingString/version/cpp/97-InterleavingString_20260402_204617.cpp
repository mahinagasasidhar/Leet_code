// Last updated: 02/04/2026, 20:46:17
1class Solution {
2public:
3    int n,m;
4    int rec(int a,int b,string& s1,string& s2,string& s3,string& f,vector<vector<int>>& dp){
5        if(a == n && b == m){
6            if(f == s3) return 1;
7            else return 0;
8        }
9        if(dp[a][b] != -1) return dp[a][b]; 
10        int ways = 0;
11        int size = f.size();
12        for(int i=a;i<n;i++){
13            f += s1[i];
14            if(f == s3.substr(0,f.size())) ways |= rec(i+1,b,s1,s2,s3,f,dp);
15        }
16        f.resize(size);
17        for(int i=b;i<m;i++){
18        f += s2[i];
19        if(f == s3.substr(0,f.size())) ways |= rec(a,i+1,s1,s2,s3,f,dp);
20        }
21        return dp[a][b] = ways;
22    }
23    bool isInterleave(string s1, string s2, string s3) {
24        n = s1.size();
25        m = s2.size();
26        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
27        string f = "";
28        return rec(0,0,s1,s2,s3,f,dp);
29    }
30};