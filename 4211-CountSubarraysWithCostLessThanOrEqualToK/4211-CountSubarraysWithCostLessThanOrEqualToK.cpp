// Last updated: 01/04/2026, 19:23:41
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long cnt = 0;
        multiset<long long> st;
        int l = 0;
        for(int r = 0;r < n; r++){
            st.insert(nums[r]);
            while((*st.rbegin() - *st.begin())*(1LL)*(r - l + 1) > k){
                st.erase(st.find(nums[l]));
                l++;
            }   
            cnt += r - l + 1;
        }
        return cnt;
    }
};