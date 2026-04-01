// Last updated: 01/04/2026, 19:27:29
class Solution {
public:
    bool isIsomorphic(string s, string t) {
    unordered_map<char,int> mp1;
    unordered_map<char,int> mp2;
    for(int i = 0;i<s.size();i++){
        if(mp1.find(s[i]) == mp1.end()){
            mp1[s[i]] = i;
        }
        if(mp2.find(t[i]) == mp2.end()){
            mp2[t[i]] = i;
        }
        if(mp1[s[i]] != mp2[t[i]]){
        return false;
        }
    }  
    return true;
    }
};