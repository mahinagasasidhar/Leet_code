// Last updated: 01/04/2026, 19:29:12
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int sum = 0;
        int i = n - 1;
        while(i>=0){
            if(i > 0 && s[i-1] == 'I' && s[i] == 'V') {
                sum +=4;
                i = i - 2;
                continue;
            }
            else if(i > 0 && s[i-1] == 'I' && s[i] == 'X') {
                sum += 9;
                i = i - 2;
                continue;
            }
            else if(i > 0 && s[i-1] == 'X' && s[i] == 'L') {
                sum +=40;
                i = i - 2;
                continue;
            }
            else if(i > 0 && s[i-1] == 'X' && s[i] == 'C') {
                sum +=90;
                i = i - 2;
                continue;
            }
            else if(i > 0 && s[i-1] == 'C' && s[i] == 'D') {
                sum += 400;
                i = i - 2;
                continue;
            }
            else if(i > 0 && s[i-1] == 'C' && s[i] == 'M') {
                sum +=900;
                i = i - 2;
                continue;
            }
            else if(s[i] == 'I') sum += 1;
            else if(s[i] == 'V') sum += 5;
            else if(s[i] == 'X') sum += 10;
            else if(s[i] == 'L') sum += 50;
            else if(s[i] == 'C') sum += 100;
            else if(s[i] == 'D') sum += 500;
            else if(s[i] == 'M') sum += 1000;
            i--;
        }
        return sum;
    }
};