// Last updated: 01/04/2026, 19:29:03
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) == string::npos) return -1;
        else return haystack.find(needle);
    }
};