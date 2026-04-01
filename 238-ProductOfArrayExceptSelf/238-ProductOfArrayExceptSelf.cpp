// Last updated: 01/04/2026, 19:27:12
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     int n =nums.size();
     int p = 0;
     vector<int> ans;
     int cnt = 0;
     for(int i =0;i<n;i++){
        if(!nums[i]) cnt++;
        else{
            if(!p) p = nums[i];
            else p *= nums[i];
        }
     }
     for(int i=0;i<n;i++){
        if(cnt == 1){
            if(nums[i] == 0) ans.push_back(p);
            if(nums[i]!=0) ans.push_back(0);
        }else if(cnt >= 2){
            ans.push_back(0);
        }
        else ans.push_back(p/nums[i]);
    
     }  
     return ans;
    }
};