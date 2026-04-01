// Last updated: 01/04/2026, 19:25:32
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        map<int,int> count,freq;
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(count.find(nums[i])!=count.end()){
                freq[count[nums[i]]]--;
                if(freq[count[nums[i]]] == 0) freq.erase(count[nums[i]]);
            }
            count[nums[i]]++;
            freq[count[nums[i]]]++;
            int maxf = freq.rbegin()->first;
            int minf = freq.begin()->first;
            int len = i+1;
            if(maxf == 1) ans = len;
            else if(freq[maxf] == 1 && freq[maxf]*maxf + freq[maxf-1]*(maxf-1) == len) ans = len;
            else if(minf == 1 && freq[minf] == 1 && freq[maxf]*maxf+1 == len) ans = len;
        }
        return ans;
    }
};