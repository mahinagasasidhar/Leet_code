// Last updated: 01/04/2026, 19:25:46
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        int maxlen = 0;
        int cnt = 0;
        int l = 0;
        for(int r = 0;r<n;r++){
            if(nums[r] == 0) cnt++;
            while(cnt > k && l<n){
                cnt -= (nums[l] == 0 ? 1 : 0);
                l++;
            }
            len = r-l+1;
            maxlen = max(maxlen,len);
        }
        return maxlen;          
    }
};