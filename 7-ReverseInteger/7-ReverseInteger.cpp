// Last updated: 01/04/2026, 19:29:17
class Solution {
public:
    int reverse(int x) {
    long long revdigit = 0;
    while(x!=0){
      int lasdigit =  x%10;
      x = x/10;
      revdigit = lasdigit + revdigit*10;
    }
    if(revdigit>INT_MAX||revdigit<INT_MIN) return 0;
    else return revdigit;
    }
};