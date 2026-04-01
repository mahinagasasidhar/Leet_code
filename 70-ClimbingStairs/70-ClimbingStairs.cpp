// Last updated: 01/04/2026, 19:28:31
class Solution {
public:
    int climbStairs(int n) {
        if(n < 2) return 1;
        int prev_1 = 1;
        int prev_2 = 1;
        int ways;
        for(int i = 2;i <= n;i++){
            ways = prev_1 + prev_2;
            prev_2 = prev_1;
            prev_1 = ways;
        }
        return ways;
    }
};