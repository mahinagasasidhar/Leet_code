// Last updated: 01/04/2026, 19:26:37
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       int n = nums.size();
       unordered_map<int,int> prev;
       prev[0] = 1;
       for(auto x : nums){
       unordered_map<int,int> pres;
       for(auto& [k,v] : prev){
       pres[k - x] += v;
       pres[k + x] += v;
       }   
       prev = pres;
       }
       return prev[target];
    }
};