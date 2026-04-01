// Last updated: 01/04/2026, 19:25:36
class Solution {
public:
    /*int rec(int i,vector<vector<int>>& books, int shelfWidth,vector<int>& dp,int n){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int totalwidth = 0;
        int height = 0;
        int ans = INT_MAX;
        for(int j=i;j<n;j++){
           totalwidth += books[j][0];
           if(totalwidth > shelfWidth) break;
           height = max(height,books[j][1]);
           ans = min(ans,height + rec(j+1,books,shelfWidth,dp,n));
        }
        return dp[i] = ans;
    }*/
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1,1e9);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--){
            int totalwidth = 0;
            int height = 0;
            for(int j=i;j<n;j++){
                    totalwidth += books[j][0];
                    if(totalwidth > shelfWidth) break;
                    height = max(height,books[j][1]);
                    dp[i] = min(dp[i],height+dp[j+1]);
            }
        }
        return dp[0];
    }
};