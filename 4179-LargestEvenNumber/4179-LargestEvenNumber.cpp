// Last updated: 01/04/2026, 19:23:55
class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        string ans = "";
        for(int i = n - 1;i >=0 ;i--){
            if(s[i] == '2'){
                ans = s.substr(0,i+1);
                return ans;
            }
        }
        return "";
    }
};