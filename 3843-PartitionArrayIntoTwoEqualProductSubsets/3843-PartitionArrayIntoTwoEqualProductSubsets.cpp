// Last updated: 01/04/2026, 19:24:29
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
      long double total = 1;
      for(auto x : nums) total *= x;
      if(total/target != target) return false;
      for(int mask=0;mask < (1<<n);mask++){
        long long prod = 1;
        for(int i = 0;i < n;i++){
            if(mask & (1<<i)) prod *= nums[i];
        }
        if(prod == target && total/prod == target) return true;
      }
      return false;
    }
};