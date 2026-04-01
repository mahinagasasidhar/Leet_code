// Last updated: 01/04/2026, 19:25:29
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        mp[0] = 1;
        for(int r=0;r<n;r++){
            sum += (nums[r]%2 == 1 ? 1 : 0);
            if(mp.find(sum - k) != mp.end()) ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};