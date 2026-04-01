// Last updated: 01/04/2026, 19:28:49
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int far = 0;
        int cnt = 0;
        while(r < n-1){
            for(int i = l;i <= r; i++){
                far = max(far,i + nums[i]);
            }
            l = r+1;
            r = far;
            cnt++;
        }
        return cnt;
    }
};