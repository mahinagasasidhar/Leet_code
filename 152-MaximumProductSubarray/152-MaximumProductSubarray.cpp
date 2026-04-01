// Last updated: 01/04/2026, 19:27:44
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int minn = nums[0];
        int maxx = nums[0];
        for(int i = 1;i < n;i++){
            int last_min = minn;
            int last_max = maxx;
            minn = min({nums[i],nums[i]*last_min,nums[i]*last_max});
            maxx = max({nums[i],nums[i]*last_min,nums[i]*last_max});
            ans = max(ans,maxx);
        }
        return ans;
    }
};