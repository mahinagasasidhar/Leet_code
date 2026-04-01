// Last updated: 01/04/2026, 19:26:26
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int r=0;r<nums.size();r++){
            sum += nums[r];
            if(mp.find(sum - k) != mp.end()) ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};