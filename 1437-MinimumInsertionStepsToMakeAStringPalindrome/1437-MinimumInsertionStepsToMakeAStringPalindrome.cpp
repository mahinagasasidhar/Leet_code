// Last updated: 01/04/2026, 19:25:26
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int m = n;
        string t = s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                if(s[i] == t[j]) dp[i][j] = max(dp[i][j],1+dp[i+1][j+1]);
            }
        }
        return n-dp[0][0];
    }
};