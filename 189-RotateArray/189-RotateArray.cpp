// Last updated: 01/04/2026, 19:27:35
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int n= nums.size();
    int d=k%n;
    vector<int>temp(d);
    for(int i=n-d;i<n;i++){
        temp[i-(n-d)]=nums[i];
    }
    for(int i=0;i<n-d;i++){
        nums[n-i-1]=nums[n-d-1-i];
    }
    for(int i=0;i<d;i++){
        nums[i]=temp[i];
    }
        
    }
};