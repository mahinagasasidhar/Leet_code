// Last updated: 01/04/2026, 19:25:39
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int> dp;
        sort(words.begin(),words.end(),[](auto& a,auto& b){
            if(a.size()<b.size()) return true;
            return false;
        });
        int best = 1;
        for(int i=0;i<n;i++){
            dp[words[i]] = 1;
            for(int j=0;j<words[i].size();j++){
                string s = words[i].substr(0,j) + words[i].substr(j+1);
                if(dp.count(s)) dp[words[i]] = max(dp[words[i]],1+dp[s]);
            }
            best = max(best,dp[words[i]]);
        }
        return best;
    }
};