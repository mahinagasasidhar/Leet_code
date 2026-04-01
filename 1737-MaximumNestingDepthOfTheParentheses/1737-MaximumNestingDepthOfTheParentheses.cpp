// Last updated: 01/04/2026, 19:25:11
class Solution {
public:
    int maxDepth(string s) {
        int dep = 0;
        int curdep = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                curdep += 1;
            }
            if(s[i] == ')'){
                curdep += -1;
            }
            dep = max(dep,curdep);
        }
        return dep;
    }
};