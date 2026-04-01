// Last updated: 01/04/2026, 19:25:28
class Solution {
public:
   bool possible(vector<int>& nums,int div,int threshold){
    int n = nums.size();
    int divsum =0;
    for(int i=0;i<n;i++){
     divsum = divsum+ceil((double)nums[i]/div);
    }
    if(divsum<=threshold){
        return true;
    }
    else{
        return false;
    }
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
    int  n = nums.size();
    int maxel =0;
    for( auto el : nums){
      maxel = max(maxel,el);  
    }
    int low = 1;
    int high = maxel;
    int ans =0;
    while(low<=high){
       int mid = low+(high-low)/2;
       if(possible(nums,mid,threshold)){
       ans = mid;
      high = mid-1;
       }
       else{
          low = mid+1;
       }
    }
    return ans;
    }
};