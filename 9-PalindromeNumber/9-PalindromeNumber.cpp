// Last updated: 01/04/2026, 19:29:14
class Solution {
public:
    bool isPalindrome(int x) {
    int num =x;
    long long revdig =0;
     if(x<0){
        return false;
     }
     while(x!=0){
     int lastdigit = x%10;
     x = x/10;
     revdig = lastdigit + revdig*10;
     }
     if(num==revdig) return true;
     else return false;
    }
};