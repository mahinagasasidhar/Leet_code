// Last updated: 05/04/2026, 08:26:44
1class Solution {
2public:
3    vector<int> findGoodIntegers(int n) {
4        long long upperbound = cbrt(n);
5        unordered_map<long long,int> mp;
6        for(long long i=1;i<=upperbound;i++){
7            for(long long j=i;j<=upperbound;j++){
8                long long value = i*i*i + j*j*j;
9                if(value <= n) mp[value]++;
10            }
11        }
12        vector<int> ans;
13        for(auto& [k,v] : mp) if(v >= 2) ans.push_back(k);
14        sort(ans.begin(),ans.end());
15        return ans;
16    }
17};