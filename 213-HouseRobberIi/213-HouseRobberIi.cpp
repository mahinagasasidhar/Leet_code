// Last updated: 01/04/2026, 19:27:25
class Solution {
    int money(vector<int>& nums,vector<int>& dp,int i,int end){
        if(i > end){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int ans = money(nums,dp,i+1,end);
        ans = max(ans,nums[i] + money(nums,dp,i+2,end));
        return dp[i] = ans;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n,-1);
        int take = money(nums,dp,0,n-2);
        fill(dp.begin(),dp.end(),-1);
        int nottake = money(nums,dp,1,n-1);
        return max(take,nottake);
    }
};