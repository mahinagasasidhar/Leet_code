// Last updated: 01/04/2026, 19:24:21
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
      int n = nums.size();
      int ans = 0;
      for(int j = 0; j <= 30;j++){
        vector<int> lis;
        for(int i = 0; i < n;i++){
        if(nums[i]&(1<<j)){
            if(lis.empty()||lis.back() < nums[i]) lis.push_back(nums[i]);
            else{
                auto it = lower_bound(lis.begin(),lis.end(),nums[i]);
                *it = nums[i];
            }
        }
        }
        ans = max(ans,(int)lis.size());
      }
      return ans;
    }
};