// Last updated: 01/04/2026, 19:27:38
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i=0;i<n;i++){
            int comp = target - numbers[i];
            auto it = lower_bound(numbers.begin()+i+1,numbers.end(),comp);
            if(it != numbers.end()){
                if(*it == comp){
                    int idx = it - numbers.begin();
                    return {i+1,idx+1};
                }
            }
        }
        return {};
    }
};