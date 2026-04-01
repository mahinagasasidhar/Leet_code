// Last updated: 01/04/2026, 19:26:30
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    int sum = 0;
    unordered_map<int,int> mp;
    mp[0] = -1;
    for(int r=0;r<n;r++){
        sum += (nums[r] == 1 ? 1 : -1);
        if(mp.find(sum) != mp.end()){
            ans = max(ans,r - mp[sum]);
        }
        else{
            mp[sum] = r;
        }
    }
    return ans;
    }
};