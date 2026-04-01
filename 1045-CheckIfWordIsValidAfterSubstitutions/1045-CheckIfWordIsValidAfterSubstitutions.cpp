// Last updated: 01/04/2026, 19:25:48
class Solution {
public:
    bool isValid(string s) {
        while(!s.empty()){
            if(s.find("abc") != string::npos) s.erase(s.find("abc"),3);
            else if(s.find("abc") == string::npos && !s.empty()) return 0;
        }
        return 1;
    }
};