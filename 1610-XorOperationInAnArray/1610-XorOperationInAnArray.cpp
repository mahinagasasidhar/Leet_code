// Last updated: 01/04/2026, 19:25:17
class Solution {
public:
    int xorOperation(int n, int start) {
        int x = 0;
        for(int i=0;i<n;i++){
            x = x^(start + (i<<1));
        }
        return x;
    }
};