// Last updated: 01/04/2026, 19:23:46
class Solution {
public:
    int countMonobit(int n) {
        if(n == 0) return 1;
       int cnt = 1;
        cnt += log2(n + 1);
        return cnt;
    }
};