// Last updated: 01/04/2026, 19:23:44
class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();
        vector<int> idx;
        string ch = "";
        string nch = "";
        for(int i = 0; i < n; i++){
            if(!(s[i] >= 'a' && s[i] <= 'z')){
                idx.push_back(i);
                nch +=s[i];
        }
            else{
                ch += s[i];
            }
        }
            reverse(ch.begin(),ch.end());
            reverse(nch.begin(),nch.end());
            string ans(n,'.');
            int c = 0;
            for(auto it : idx){
                ans[it] = nch[c++];
            }
            c = 0;
            for(int i = 0;i < n;i++){
                if(ans[i] == '.') ans[i] = ch[c++];
            }
            return ans;
    }
};