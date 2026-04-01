// Last updated: 01/04/2026, 19:25:30
class Solution {
public:
    int rec(int i,vector<int>& starttime, vector<int>& endtime, vector<int>& profit,vector<int>& dp){
        if(i >= starttime.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        ans = rec(i+1,starttime,endtime,profit,dp);
        int idx = lower_bound(starttime.begin(),starttime.end(),endtime[i]) - starttime.begin();
        ans = max(ans,profit[i] + rec(idx,starttime,endtime,profit,dp));
        return dp[i] = ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> p;
        for(int i=0;i<n;i++) p.push_back({startTime[i],endTime[i],profit[i]});
        sort(p.begin(),p.end());
        for(int i=0;i<n;i++){
            startTime[i] = p[i][0];
            endTime[i] = p[i][1];
            profit[i] = p[i][2];
        }
        vector<int> dp(n,-1);
        int a = rec(0,startTime,endTime,profit,dp);
        return *max_element(dp.begin(),dp.end());
    }
};