// Last updated: 01/04/2026, 19:27:11
class Solution {
public:
    bool isAnagram(string s, string t) {
      vector<int> freq(26,0);
      for(auto& x : s) freq[x - 'a']++;
      for(auto& x : t) freq[x - 'a']--;
      for(auto& x : freq){
        if(x!=0) return false;
      }
      return true;
    }
};