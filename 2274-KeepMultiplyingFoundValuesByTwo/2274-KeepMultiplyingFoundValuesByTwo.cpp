// Last updated: 01/04/2026, 19:24:49
class Solution {
public:
    bool isexist(vector<int>& nums, int original){
    for(auto x : nums){
        if(x == original) return true;
       
    }
    return false;
    }
    int findFinalValue(vector<int>& nums, int original) {
    if(isexist(nums, original)) return findFinalValue(nums,original*2);
    return original;
    }
};