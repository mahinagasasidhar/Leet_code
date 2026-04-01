// Last updated: 01/04/2026, 19:27:19
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n >0 && (n&(n -1)) == 0;
    }
};