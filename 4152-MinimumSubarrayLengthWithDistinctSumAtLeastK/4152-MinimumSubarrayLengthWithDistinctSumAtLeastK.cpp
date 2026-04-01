// Last updated: 01/04/2026, 19:24:06
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int len = INT_MAX;
        int sum = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            mp[nums[r]]++;
            if(mp[nums[r]] == 1){
                sum += nums[r];
            }
            while(sum >= k){
                len = min(len,r - l + 1);
                if(mp[nums[l]] == 1) sum -= nums[l];
                mp[nums[l++]]--;
            }
        }
        return (len == INT_MAX ? -1 : len);
    }
};