// Last updated: 01/04/2026, 19:23:34
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n);
        mx[0]=nums[0];
        for(int i = 1; i < n;i++){
         mx[i] = max(mx[i-1],nums[i]);
        }
        vector<int> vgcd(n);
        for(int i = 0; i < n;i++){
            vgcd[i] = gcd(nums[i],mx[i]);
        }
        sort(vgcd.begin(),vgcd.end());
        mx.clear();
        int i = 0;
        int j = n-1;
        while(i < j){
            mx.push_back(gcd(vgcd[i],vgcd[j]));
            i++;
            j--;
        }
        long long ans = accumulate(mx.begin(),mx.end(),0LL);
        return ans;
    }
};