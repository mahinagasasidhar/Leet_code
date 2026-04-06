// Last updated: 06/04/2026, 18:56:12
1class Solution {
2public:
3    int gaps(int i,int end){
4        int l = end - i + 1;
5        return (l + 1)/2;
6    }
7    vector<long long> cost;
8    long long rec(int i,int end,vector<vector<int>>& dp,int k){
9        if(i > end){
10            if(k == 0) return 0;
11            else return INT_MAX;
12        }
13        if(k == 0) return 0;
14        if(dp[i][k] != -1) return dp[i][k];
15        long long skip = INT_MAX;
16        long long take = INT_MAX;
17        if(gaps(i+1,end) >= k) skip = rec(i+1,end,dp,k);
18        take = min(take,cost[i] + rec(i+2,end,dp,k-1));
19        return dp[i][k] = min(skip,take);
20    }
21    int minOperations(vector<int>& nums, int k) {
22      int n = nums.size();
23      int gaps = n/2;
24      if(gaps < k) return -1;
25      for(int i=0;i<n;i++) cost.push_back(max(0,max(nums[(i-1+n)%n],nums[(i+1)%n])-nums[i] + 1));
26      vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
27      int a = rec(0,n-2,dp,k);
28      dp.assign(n+1,vector<int>(k+1,-1));
29      int b = rec(1,n-1,dp,k);
30      return min(a,b);
31    }
32};