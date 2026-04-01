// Last updated: 01/04/2026, 19:25:41
class Solution {
public:
    int n,m;
    int rec(int i,int j,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>& dp){
        if(i >= n || j>= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans = rec(i+1,j,nums1,nums2,dp);
        ans = max(ans,rec(i,j+1,nums1,nums2,dp));
        if(nums1[i] == nums2[j]) ans = max(ans,1+rec(i+1,j+1,nums1,nums2,dp));
        return dp[i][j] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(0,0,nums1,nums2,dp);
    }
};