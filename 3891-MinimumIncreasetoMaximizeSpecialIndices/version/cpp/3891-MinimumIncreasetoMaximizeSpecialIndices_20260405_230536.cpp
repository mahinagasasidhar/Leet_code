// Last updated: 05/04/2026, 23:05:36
1class Solution {
2public:
3    vector<long long> cost;
4    vector<vector<long long>> dp;
5    long long n;
6    long long rec(int i,int taken){
7        if(i >= n-1) return 0;
8        if(dp[i][taken] != -1) return dp[i][taken];
9        long long skip = 1e18;
10         long long take = rec(i+2,taken) + cost[i];
11         if(taken == 0){
12            skip = rec(i+1,1);
13         }
14        return dp[i][taken] = min(skip,take);
15    }
16    long long minIncrease(vector<int>& nums) {
17        n = nums.size();
18        cost.resize(n);
19        dp.assign(n,vector<long long>(2,-1));
20        for(int i=1;i<n-1;i++) cost[i] = max(0,max(nums[i-1],nums[i+1]) - nums[i] + 1);
21        long long total = 0;
22        if(n%2 == 1) {
23            for(int i=1;i<n;i+=2) total += cost[i];
24        return total;
25        }
26        return rec(1,0);
27    }
28};