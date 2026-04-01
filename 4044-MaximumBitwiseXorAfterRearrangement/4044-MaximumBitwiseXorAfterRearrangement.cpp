// Last updated: 01/04/2026, 19:24:19
class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.size();
        int cnt0 = 0;
        int cnt1 = 0;
        for(int i = 0; i < n;i++){
            if(t[i] == '0') cnt0++;
            else cnt1++;
        }
        t.erase(0,n);
        for(int i = 0; i < n;i++){
            if(s[i] == '0' && cnt1){
                cnt1--;
                t += '1';
            }
            else if(s[i] == '0' && !cnt1){
             cnt0--;
             t+='0';
            }
            else if(s[i] == '1' && cnt0){
                 cnt0--; t+= '0';
            }
            else if(s[i] == '1' && !cnt0){
                 cnt1--; t+= '1';
            }
        }
        string ans;
        for(int i = 0; i < n;i++){
            if(s[i] == '0' && t[i] == '0') ans += '0';
            else if(s[i] == '0' && t[i] == '1') ans += '1';
            else if(s[i] == '1' && t[i] == '1') ans += '0';
            else ans += '1'; 
        }
        return ans;
    }
};