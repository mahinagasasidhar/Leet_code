// Last updated: 01/04/2026, 19:26:13
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        return (s + s).find(goal) != string::npos;
    }
};