// Last updated: 01/04/2026, 19:26:23
class Solution {
public:
    /*int rec(int level,vector<int>& dp,vector<int>& nums){
        if(level < 0) return 0;
        if(dp[level] != -1) return dp[level];
        int ans = 1;
        for(int i=0;i<level;i++){
            if(nums[i] < nums[level]) ans = max(ans,1+rec(i,dp,nums));
        }
        return dp[level] = ans;
    }*/
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                     if(1 + dp[j] > dp[i]){
                        dp[i] = 1+dp[j];
                        cnt[i] = cnt[j];
                     }else if(1+dp[j] == dp[i]) cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi) ans += cnt[i];
        }
        return ans;
    }
};