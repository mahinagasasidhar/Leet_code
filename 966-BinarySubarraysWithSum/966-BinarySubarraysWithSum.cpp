// Last updated: 01/04/2026, 19:25:55
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int presum = 0;
        unordered_map<int,int> mp;
        mp[0]++;
        int cnt = 0;
        for(int i=0;i<n;i++){
            presum += nums[i];
            if(mp.find(presum- goal) != mp.end()){
                cnt += mp[presum-goal];
            }
            mp[presum]++;
        }  
        return cnt;   
    }
};