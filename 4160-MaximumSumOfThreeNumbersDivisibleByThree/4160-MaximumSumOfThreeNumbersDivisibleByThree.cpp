// Last updated: 01/04/2026, 19:24:04
class Solution {
public:
    int maximumSum(vector<int>& nums) {
       int n = nums.size();
       multiset<int> rem0;
       multiset<int> rem1;
       multiset<int> rem2;
       for(int i = 0; i < n; i++){
        if(nums[i] % 3 == 0){
            rem0.insert(nums[i]);
        }
        else if(nums[i] % 3 == 1){
            rem1.insert(nums[i]);
        }
        else rem2.insert(nums[i]);
       }
       vector<int> tp;
       int maxsum = 0;
       if(rem0.size() >= 3){
        int sum = 0;
        auto it = rem0.end();
        for(int i = 0;i < 3;i++){
            --it;
            sum += *it;
            maxsum = max(maxsum,sum);
        }
       }
       if(rem1.size() >= 3){
        int sum = 0;
        auto it = rem1.end();
        for(int i = 0;i < 3;i++){
            --it;
            sum += *it;
            maxsum = max(maxsum,sum);
        }
       }
        if(rem2.size() >= 3){
        int sum = 0;
        auto it = rem2.end();
        for(int i = 0;i < 3;i++){
            --it;
            sum += *it;
            maxsum = max(maxsum,sum);
        }
    }
    if(rem1.size() > 0 && rem0.size() > 0 && rem2.size() > 0){
        int sum = 0;
        auto it1 = rem0.rbegin();
        auto it2 = rem1.rbegin();
        auto it3 = rem2.rbegin();
        sum += *it1 + *it2 + *it3;
        maxsum = max(maxsum,sum);
    }
       return maxsum;
    }
};