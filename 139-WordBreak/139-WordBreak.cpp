// Last updated: 01/04/2026, 19:27:54
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,0);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
           for(int j=i;j<n;j++){
            if(st.count(s.substr(i,j-i+1))){
                if(dp[j+1]) dp[i] = 1;
            }
           } 
        }
        return dp[0];
    }
};