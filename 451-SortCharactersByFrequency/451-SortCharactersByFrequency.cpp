// Last updated: 01/04/2026, 19:26:43
class Solution {
public:
    string frequencySort(string s) {
    string ans;
    unordered_map<char,int> mp;
    for(auto it : s) mp[it]++;
    vector<pair<char,int>> freq(mp.begin(),mp.end());
    sort(freq.begin(),freq.end(),[](auto& a,auto& b){
        return a.second > b.second;
    });
    for(auto ch : freq){
    ans.append(ch.second,ch.first);
    }
    return ans;
    }
};