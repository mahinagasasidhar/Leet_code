// Last updated: 01/04/2026, 19:25:38
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;
        for(auto x : stones) total += x;
        int target = total/2;
        vector<int> dp(target+1,0);
        if(stones[0] <= target) dp[stones[0]] = 1;
        dp[0] = 1;
        for(int i=1;i<n;i++){
            for(int j = target;j>=0;j--){
                if(j >= stones[i]) dp[j] |= dp[j-stones[i]];
            }
        }
        for(int i = target;i>=0;i--){
            if(dp[i]) return abs(total - 2*i);
        }
        return 0;
    }
};