// Last updated: 01/04/2026, 19:28:43
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int msum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            msum = max(msum,sum);
            if(sum < 0) sum = 0;
        }
        return msum;  
    }
};