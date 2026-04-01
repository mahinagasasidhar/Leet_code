// Last updated: 01/04/2026, 19:24:09
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int> mp;
        for(int i = 0; i < n; i++){
            if(words[i].size() < k) continue;
            string word = "";
            for(int j = 0;j < k && words[i].size();j++){
                word += words[i][j];
            }
            mp[word]++;
        }
        int cnt = 0;
        for(auto& it : mp){
            if(it.second >= 2) cnt++;
        }
        return cnt;
    }
};