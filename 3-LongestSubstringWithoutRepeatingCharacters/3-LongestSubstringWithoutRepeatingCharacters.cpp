// Last updated: 01/04/2026, 19:29:20
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> mp(256,-1);
        int l = 0;
        int curlen = 0;
        int maxlen = 0;
        for(int r=0;r<n;r++){
            if(mp[s[r]] != -1){
                if(l<=mp[s[r]]){
                    l = mp[s[r]]+1;
                }
            }
                curlen = r-l+1;
                maxlen = max(maxlen,curlen);
                mp[s[r]] = r;              
        }
        return maxlen;  
    }
};