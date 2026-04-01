// Last updated: 01/04/2026, 19:23:36
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        __int128 lsum = 0;
        __int128 sat = 2000000000000000ULL;
        vector<__int128> prod(n);
        __int128 pro = 1;
        
        bool overflowed = false;
        for(int i = n - 1 ; i >= 0; i--){
            if(overflowed) {
                prod[i] = sat + 7;
            } else {
                pro *= nums[i];
                if(pro > sat) {
                    overflowed = true;
                    prod[i] = sat + 7;
                } else {
                    prod[i] = pro;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(i != 0) lsum += nums[i-1];
            
            if(i == n - 1){
                if(lsum == 1) return n - 1;
                else continue;
            }

            if(prod[i+1] == lsum){
                return i;
            }
        }
        return index;
    }
};