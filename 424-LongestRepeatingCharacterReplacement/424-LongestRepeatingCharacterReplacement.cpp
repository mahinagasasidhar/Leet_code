// Last updated: 01/04/2026, 19:26:46
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> mp(26,0);
        int maxlen = 0;
        int len = 0;
        int maxfreq = 0;
        int l = 0;
        for(int r=0;r<n;r++){
            mp[s[r] - 'A']++;
            maxfreq = max(maxfreq,mp[s[r] - 'A']);
            int changes = (r-l+1) - maxfreq;
            while(changes > k){
                mp[s[l] - 'A']--;
                l++;
                changes = (r-l+1) - maxfreq;   
            }
            maxlen = max(maxlen,r-l+1);
        } 
        return maxlen;
    }
};