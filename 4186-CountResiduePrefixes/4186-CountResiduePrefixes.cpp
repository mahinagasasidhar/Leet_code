// Last updated: 01/04/2026, 19:23:52
class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();
        int cnt = 0;
      unordered_map<char,int> mp;
        for(int i =0 ;i<n;i++){
            mp[s[i]]++;
            if(mp.size() == ((1 + i)%3)) cnt++;
        }
        return cnt;
    }
};