// Last updated: 01/04/2026, 19:29:19
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int c=0;c<2*n-1;c++){
            int l = c/2;
            int r = l + c%2;
            while(l>=0 && r<n && s[l] == s[r]){
                if((r-l+1) > ans.size()){
                    ans = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};