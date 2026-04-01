// Last updated: 01/04/2026, 19:24:01
class Solution {
public:
    int mirrorDistance(int n) {
        long long x = n;
        long long revdigit = 0;
        while( n!= 0){
            int lasdigit = n%10;
            n = n/10;
            revdigit = 1LL*10*(revdigit) + lasdigit;
        } 
        return abs(x - revdigit);          
    }
};