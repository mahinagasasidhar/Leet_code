// Last updated: 01/04/2026, 19:23:21
class Solution {
public:
    int firstMatchingIndex(string s) {
        int i=0;
        int n = s.size();
       while(i < n){
           if(s[i] == s[n-i-1]) return i;
           i++;
       } 
        return -1;
    }
};