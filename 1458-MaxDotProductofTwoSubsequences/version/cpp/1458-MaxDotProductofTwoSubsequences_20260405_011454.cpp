// Last updated: 05/04/2026, 01:14:54
1class Solution {
2public:
3    int n,m;
4    vector<vector<int>> dp;
5    int rec(int i,int j,vector<int>& a, vector<int>& b){
6        if(i == n || j == m) return -1e9;
7        if(dp[i][j] != -1) return dp[i][j];
8        int ans = 1e9;
9        int take = a[i]*b[j] + max(0,rec(i+1,j+1,a,b));
10        int skip1 = rec(i+1,j,a,b);
11        int skip2 = rec(i,j+1,a,b);
12        return dp[i][j] =max({take,skip1,skip2});
13    }
14    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
15        n = nums1.size();
16        m = nums2.size();
17        dp.assign(n,vector<int>(m,-1));
18        return rec(0,0,nums1,nums2);
19    }
20};