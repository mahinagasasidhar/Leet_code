// Last updated: 01/04/2026, 19:27:06
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long x = 0;
        for(int i=0;i<nums.size();i++){
            x ^= nums[i];
        }
            long mask = x & (-x);
            int a = 0;
            int b = 0;
            for(auto n : nums){
                if((n & mask) == 0) a ^= n;
                else b ^= n;
            }
            return {a,b};
    }
};