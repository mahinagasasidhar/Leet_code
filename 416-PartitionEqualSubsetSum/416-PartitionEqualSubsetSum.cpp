// Last updated: 01/04/2026, 19:26:47
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int target = total/2;
        if(total%2) return 0;
        vector<int> dp(total+1,0);
        dp[0] = 1;
        for(int x : nums){
            for(int sum = target;sum >= x;sum--){
                if(dp[sum - x]) dp[sum] = 1;
            }
        }
        return dp[target];
    }
};