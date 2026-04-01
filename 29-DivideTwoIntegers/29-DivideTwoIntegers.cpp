// Last updated: 01/04/2026, 19:29:01
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool sign = true;
        long cnt = 0;
        long ans = 0;
        if(dividend < 0 && divisor > 0) sign = false;
        if(dividend > 0 && divisor < 0) sign = false;
        long n = abs((long)dividend);
        long d = abs((long)divisor);
        while(n >= d){
            cnt = 0;
            while(n >= (d<<(cnt+1))) cnt++;
            ans += 1<<(cnt);
            n -= (d<<(cnt));
        }
        if(ans == INT_MAX && sign) return INT_MAX;
        return sign ? ans : -ans;
    }
};