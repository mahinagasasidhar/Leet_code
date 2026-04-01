// Last updated: 01/04/2026, 19:23:54
class Solution {
public:
    unordered_map<string,long long> mp;
    void normalization(string s){
        string t;
        for(int i = 0; i < s.size();i++){
            t += (s[i] - s[0] + 26) % 26 ;
        }
        mp[t]++;
    }
    long long countPairs(vector<string>& words) {
        for(auto &w : words){
            normalization(w);
        }
        long long ans= 0;
        for(auto it : mp){
            ans += it.second*(it.second - 1)/2;
        }
        return ans;
    }
};