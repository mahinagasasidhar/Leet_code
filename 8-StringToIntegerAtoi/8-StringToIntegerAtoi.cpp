// Last updated: 01/04/2026, 19:29:16
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1;
        long long res = 0;
        int digit = 0;
        while(i<n && s[i] == ' ') i++;
        if(i<n && s[i] == '+'){
            sign = 1;
            i++;
        }
        else if(i<n && s[i] == '-'){
            sign = -1;
            i++;
        }
        while(i<n && isdigit(s[i])){
            digit = s[i] - '0';
            res = res*10 + digit;
            if(sign*res < INT_MIN) return INT_MIN;
            if(sign*res > INT_MAX) return INT_MAX;
            i++;
        }
        return static_cast<int>(res*sign);
    }
};