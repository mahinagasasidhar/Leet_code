// Last updated: 01/04/2026, 19:27:56
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 0;i<nums.size();i++){
            x = x^nums[i];
        }
        return x;
    }
};