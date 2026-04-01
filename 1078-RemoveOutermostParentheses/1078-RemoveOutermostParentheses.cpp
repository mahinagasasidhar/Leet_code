// Last updated: 01/04/2026, 19:25:43
class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal = 0;
        string ans;
        for(auto ch : s){
            if(ch == '('){
                if(bal > 0){
                 ans.push_back(ch);
                }
                bal++;
            }
            else{
                bal--;
                if(bal > 0) ans.push_back(ch);
            }
        }
        return ans;
    }
};