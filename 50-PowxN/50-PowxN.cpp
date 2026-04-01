// Last updated: 01/04/2026, 19:28:45
class Solution {
public:
    double myPow(double x, int n) {
    int m = n;
    long long a = n;
    if(a < 0) a = -a;
    double ans = 1;
    while(a != 0){ 
        if((a&1) == 1){
            a = a - 1;
            ans = ans*x;
        }
        else{
            a = a>>1;
            x = x*x;
        }
    }
    if(m < 0){
        ans  =  1.0/ans;
    }
    return ans;
    }
};