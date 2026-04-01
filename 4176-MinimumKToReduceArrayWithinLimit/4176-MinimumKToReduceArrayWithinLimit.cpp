// Last updated: 01/04/2026, 19:23:59
class Solution {
public:
    int minimumK(vector<int>& nums) {
     int n = nums.size();
     if(n == 1 && nums[0] == 1) return 1;
     int ans = 0;
     for(long long k = 1; k < 10000;k++){
         int op = 0;
         long long sq = k*k;
         for(int i = 0; i < n; i++){
             op += (nums[i] + k - 1)/k;
             if(op > sq) break;
         }
         if(op <= sq){
             ans = k;
             break;
         }
     }   
        return ans;
    }
};