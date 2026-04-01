// Last updated: 01/04/2026, 19:23:58
class Solution {
public:
    string reversePrefix(string s, int k) {
      reverse(s.begin(),s.begin()+k);
        return s;
    }
};