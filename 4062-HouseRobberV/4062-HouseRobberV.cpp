// Last updated: 01/04/2026, 19:24:18
class Solution {
    private:
    int n;
    long long rec(vector<pair<int,int>>& v,vector<vector<long long>>& dp,int taken,int i){
        if(i == n) return 0;
        if(dp[i][taken] != -1) return dp[i][taken];
        long long ans = rec(v,dp,0,i+1);
        if(!(taken == 1 && v[i - 1].second == v[i].second)) ans = max(ans,v[i].first + rec(v,dp,1,i+1));
        return dp[i][taken] = ans;
    }
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
      n = nums.size();
      vector<vector<long long>> dp(n,vector<long long>(2,-1));
      vector<pair<int,int>> v;
      for(int i = 0; i < n;i++){
        v.push_back({nums[i],colors[i]});
      }  
      return rec(v,dp,0,0);
    }
};