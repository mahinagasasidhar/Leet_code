// Last updated: 01/04/2026, 19:24:15
class Solution {
public:
    int n,finaltarget;
    int rec(int i,int x,vector<int>& nums,vector<vector<int>>& dp){
        if(i == n){
            if(x == finaltarget) return 0;
            else return -50;
        }
        if(dp[i][x] != -1) return dp[i][x];
        int skip = rec(i+1,x,nums,dp);
        int take = 1+rec(i+1,x^nums[i],nums,dp);
        return dp[i][x] = max(skip,take);
    }
    int minRemovals(vector<int>& nums, int target) {
        n = nums.size();
        finaltarget = target;
        vector<vector<int>> dp(n+1,vector<int>(17000,-1));
        int a = rec(0,0,nums,dp);
        if(a < 0) return -1;
        return n - a;

    }
};