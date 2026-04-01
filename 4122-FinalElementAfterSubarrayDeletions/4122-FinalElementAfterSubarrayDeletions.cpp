// Last updated: 01/04/2026, 19:24:12
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums[0],nums[nums.size()-1]);
    }
};