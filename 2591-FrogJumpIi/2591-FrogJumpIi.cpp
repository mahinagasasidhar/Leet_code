// Last updated: 01/04/2026, 19:24:41
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int ans = 0;
        for(int i = 0;i < n-1;i++){
            ans = max(ans,stones[i+1]-stones[i]);
        } 
        for(int i = 0;i < n-2;i++){
        ans = max(ans,stones[i+2]-stones[i]);
        } 
        return ans; 
    }
};