// Last updated: 06/04/2026, 19:49:37
1class Solution {
2public:
3    const long long INF = 1e18;
4    vector<long long> cost;
5
6    long long rec(int i, int end, int k, vector<vector<long long>>& dp) {
7        if (k == 0) return 0;
8        if (i > end) return INF;
9
10        if (dp[i][k] != -1) return dp[i][k];
11
12        // skip
13        long long ans = rec(i + 1, end, k, dp);
14
15        // take
16        long long nxt = rec(i + 2, end, k - 1, dp);
17        if (nxt != INF)
18            ans = min(ans, cost[i] + nxt);
19
20        return dp[i][k] = ans;
21    }
22
23    int minOperations(vector<int>& nums, int k) {
24        int n = nums.size();
25        if (n / 2 < k) return -1;
26
27        cost.resize(n);
28        for (int i = 0; i < n; i++) {
29            cost[i] = max(0,
30                max(nums[(i - 1 + n) % n], nums[(i + 1) % n]) - nums[i] + 1
31            );
32        }
33
34        vector<vector<long long>> dp(n, vector<long long>(k + 1, -1));
35        long long a = rec(0, n - 2, k, dp);
36
37        dp.assign(n, vector<long long>(k + 1, -1));
38        long long b = rec(1, n - 1, k, dp);
39
40        return min(a, b);
41    }
42};