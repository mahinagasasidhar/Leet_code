// Last updated: 01/04/2026, 19:27:03
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int first=0;
    int second=0;
    while(second<n){
    if(nums[second]!=0){
    swap(nums[first],nums[second]);
    first++;
    second++;
    }
    else{
        second++;
    }
    }
    }
    
};