// Last updated: 01/04/2026, 19:25:25
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<int,int> mp;
        int cnt  = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            mp[s[r]]++;
            while(mp.find('a') != mp.end() && mp.find('b') != mp.end() && mp.find('c') != mp.end()){
                cnt += (n - r);
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
        }
        return cnt;
    }
};