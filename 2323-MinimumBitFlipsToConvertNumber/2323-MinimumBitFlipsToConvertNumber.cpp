// Last updated: 01/04/2026, 19:24:48
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        while(goal >= 1 || start >= 1){
        int rem1 = goal&1;
        int rem2 = start&1;
        cnt += rem1^rem2;
        goal = goal/2;
        start = start/2;
        }
        return cnt;
    }
};