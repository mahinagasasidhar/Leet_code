// Last updated: 01/04/2026, 19:25:23
class Solution {
public:
    int minSteps(string s, string t) {
       unordered_map<char,int> mp;
       for(auto x : s) mp[x]++;
       for(auto x : t) mp[x]--;
       int ans = 0;
       for(auto& [k,v] : mp) ans += abs(v);
       return ans/2;
    }
};