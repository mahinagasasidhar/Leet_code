// Last updated: 01/04/2026, 19:26:58
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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]) dp[i] = max(dp[i],1+dp[j]);
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};