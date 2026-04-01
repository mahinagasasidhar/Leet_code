// Last updated: 01/04/2026, 19:27:59
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 0) return {};
        int cnt = 1;
        int larcnt = 1;
        for(int i = 0;i+1<n;i++){
            if(nums[i+1] == nums[i]) continue;
            else if(nums[i+1] == nums[i]+1) cnt++ ;
            else{
                larcnt = max(larcnt,cnt);
                cnt  = 1;
            }
        }
        return max(larcnt,cnt);
    }
};