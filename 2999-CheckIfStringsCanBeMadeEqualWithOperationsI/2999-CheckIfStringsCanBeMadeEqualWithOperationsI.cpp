// Last updated: 01/04/2026, 19:24:38
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        //even
        bool even = (s1[0] == s2[0] && s1[2] == s2[2] )|| (s1[0] == s2[2] && s1[2] == s2[0]);
        //odd
        bool odd =  (s1[1] == s2[1] && s1[3] == s2[3]) || (s1[1] == s2[3] && s1[3] == s2[1]);
        return even && odd;
    }
};