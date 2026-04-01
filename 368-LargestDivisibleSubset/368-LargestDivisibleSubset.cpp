// Last updated: 01/04/2026, 19:26:54
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i = 1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = 1 + dp[j];
                        maxi = max(dp[i],maxi);
                    }
                }
            }
        }
        int last = 0;
        vector<int> v(maxi);
        for(int i=n-1;i>=0 && maxi > 0;i--){
            if(dp[i] == maxi && (last == 0 || nums[last] % nums[i] == 0)){
                v[maxi-1] = nums[i];
                last = i;
                maxi--;
            } 
        }
        return v;
    }
};