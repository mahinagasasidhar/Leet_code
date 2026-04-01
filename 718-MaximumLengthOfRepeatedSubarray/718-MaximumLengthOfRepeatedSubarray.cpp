// Last updated: 01/04/2026, 19:26:20
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> prev(m+1,0),cur(m+1,0);
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1] == nums2[j-1]){
                    cur[j] = 1+prev[j-1];
                    ans = max(ans,cur[j]);
                }else cur[j] = 0;
            }
            prev = cur;
        }
        return ans;
    }
};