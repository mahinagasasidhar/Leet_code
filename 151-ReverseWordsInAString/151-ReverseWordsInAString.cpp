// Last updated: 01/04/2026, 19:27:45
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        for(int j = 0;j<s.size();j++){
            if(j<n && s[j] != ' '){
                s[i++] = s[j];
            }
            else if(i>0 && s[i-1]!= ' '){
                s[i++] = ' ';
            }
        }
        if(i>0 && s[i-1] == ' ') i--;
        s.resize(i);
        reverse(s.begin(),s.end());
        int left = 0;
        for(int i=0;i<=s.size();i++){
            if(s[i] == ' ' || i == s.size()){
                reverse(s.begin()+left,s.begin()+i);
                left = i+1;
            }
        }
        return s;
    }
};