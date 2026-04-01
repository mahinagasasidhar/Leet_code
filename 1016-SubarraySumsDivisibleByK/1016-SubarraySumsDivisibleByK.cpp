// Last updated: 01/04/2026, 19:25:52
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int r=0;r<n;r++){
            sum += nums[r];
            if(mp.find((sum%k +k)%k) != mp.end()) ans += mp[(sum%k +k)%k];
            mp[(sum%k +k)%k]++;
        } 
        return ans;
    }
};