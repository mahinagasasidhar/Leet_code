// Last updated: 01/04/2026, 19:26:15
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxx = *max_element(nums.begin(),nums.end());
        vector<int> freq(maxx+1);
        for(int i=0;i<n;i++) freq[nums[i]]++;
        n = freq.size();
        vector<int> dp(n+2,0);
        int first = 0;
        int second = 0;
        for(int i=0;i<n;i++){
            int curr = max(first,freq[i]*i+second);
            second = first;
            first = curr;
        }
        return first;
    }
};