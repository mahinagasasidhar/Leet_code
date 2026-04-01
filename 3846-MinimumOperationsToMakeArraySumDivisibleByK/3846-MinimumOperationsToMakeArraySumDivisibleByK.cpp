// Last updated: 01/04/2026, 19:24:28
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(),nums.end(),0);
        int rem = sum % k;
        return rem;
    }
};