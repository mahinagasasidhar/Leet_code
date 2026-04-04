// Last updated: 05/04/2026, 01:15:46
1class Solution {
2public:
3    int n,m;
4    vector<vector<int>> dp;
5    int rec(int i,int j,vector<int>& a, vector<int>& b){
6        if(i == n || j == m) return -1e9;
7        if(dp[i][j] != -1) return dp[i][j];
8        int ans =  INT_MIN;
9        ans = max(ans,rec(i+1,j,a,b));
10        ans = max(ans,rec(i,j+1,a,b));
11        for(int k=j;k<m;k++){
12             ans = max(ans,a[i]*b[k] + max(0,rec(i+1,k+1,a,b)));
13        }
14        return dp[i][j] = ans;
15    }
16    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
17        n = nums1.size();
18        m = nums2.size();
19        dp.assign(n,vector<int>(m,-1));
20        return rec(0,0,nums1,nums2);
21    }
22};