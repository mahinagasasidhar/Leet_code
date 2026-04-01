// Last updated: 01/04/2026, 19:23:30
class Solution {
public:
    long long countCommas(long long n) {
        if(n < 0) return 0;
        long long commas = 1;
        long long ans = 0;
        for(long long start = 1000;start <=n;start*=1000,commas++){
            long long end = min(n,start*1000-1);
            long long values = end - start + 1;
            ans += values*commas;
        }
        return ans;
    }
};