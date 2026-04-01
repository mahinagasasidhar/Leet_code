// Last updated: 01/04/2026, 19:26:06
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(),nums1.end());
        vector<pair<int,int>> b;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            b.emplace_back(nums2[i],i);
        }
        sort(b.begin(),b.end());
        int l = 0;
        int r = n-1;
        int i = n - 1;
        while(l <= r){
            if(nums1[r] > b[i].first){
                ans[b[i].second] = nums1[r];
                r--;
            }
            else{
                ans[b[i].second] = nums1[l];
                l++;
            }
            i--;
        }
        return ans;
    }
};