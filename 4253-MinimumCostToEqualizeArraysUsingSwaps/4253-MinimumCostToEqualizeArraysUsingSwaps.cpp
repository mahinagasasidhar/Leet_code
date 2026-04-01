// Last updated: 01/04/2026, 19:23:27
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(auto x : nums1) mp[x]++;
        for(auto x : nums2) mp[x]--;
        int ans = 0;
        for(auto& [k,v] : mp){
            if(v%2) return -1;
            if(v < 0) ans += abs(v/2);
        }
        return ans;
    }
};