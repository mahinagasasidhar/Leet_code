// Last updated: 01/04/2026, 19:25:53
class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;

        return fib(n-1)+fib(n-2);
        
    }
};