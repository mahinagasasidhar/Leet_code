// Last updated: 01/04/2026, 19:23:24
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n =  nums1.size();
        int ecnt =0;
        int ocnt =0;
        for(auto x :nums1) if(x%2) ocnt++;
        else ecnt++;
        if(ocnt == n) return true;
        else if(ecnt == n) return true;
        else{
            int el = *min_element(nums1.begin(),nums1.end());
            if(el%2) return true;
        }
        return false;
    }
};