// Last updated: 01/04/2026, 19:29:08
class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char>st;
        for(int i=0;i<size;i++){
            if(s[i]=='{'||s[i]=='['||s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char ch = st.top();
                st.pop();
                if(s[i]=='}' && ch=='{'||s[i]==']' && ch=='['||s[i]==')' && ch=='('){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
    return st.empty();
    }
};