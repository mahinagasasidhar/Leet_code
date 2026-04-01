// Last updated: 01/04/2026, 19:24:10
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
       int n = nums.size();
        int cnt = 0;
        for(int i = 0;i < n; i++){
            unordered_map<int,int> ans;
            int sum = 0;
            for(int j = i;j < n; j++){
                ans[nums[j]]++;
                sum += nums[j];
                if(ans.find(sum) != ans.end()) cnt++;
            }
        }
        return cnt;
    }
};