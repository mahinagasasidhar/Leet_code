// Last updated: 01/04/2026, 19:27:34
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int first = 0;
        int second = 0;
        for(int i=n-1;i>=0;i--){
            int curr = max(first,nums[i]+second);
            second = first;
            first = curr;
        }
        return first;
    }
};