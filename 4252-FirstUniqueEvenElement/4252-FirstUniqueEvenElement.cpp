// Last updated: 01/04/2026, 19:23:28
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
     vector<int> ans(101,0);
     for(auto x : nums){
         if(x%2 == 0){
             ans[x] = ans[x] + 1;
         }
     }
        int a = -1;
        for(auto x : nums){
            if(x % 2 ==0 && ans[x] == 1) 
                return x;
        }
        return -1;
    }
};