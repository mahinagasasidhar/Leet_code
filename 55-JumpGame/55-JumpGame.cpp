// Last updated: 01/04/2026, 19:28:42
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxj = 0;
        int index = 0;
        for(int i = 0;i < n; ++i){
            if(i <= maxj){
                 maxj = max(maxj,i+nums[i]);
                 index = i;
            }
            else break;
        }
        return (index == n-1 ? 1 : 0);
    }
};