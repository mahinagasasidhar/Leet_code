// Last updated: 01/04/2026, 19:25:49
class Solution {
public:
    int subatmostk(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int> mp;
        int l = 0;
        int ans =0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            ans += i-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subatmostk(nums, k) - subatmostk(nums, k-1);
   }
};