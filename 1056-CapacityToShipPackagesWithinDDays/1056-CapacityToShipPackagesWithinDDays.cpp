// Last updated: 01/04/2026, 19:25:44
class Solution {
public:
    bool possible(vector<int>& weights, int capacity,int days){
    int n = weights.size();
    int sum =0;
    int day =0;
    for(int i=0;i<n;i++){
        sum = sum+weights[i];
        if((double)sum/capacity<=1){
         continue;
        }
       else{
         day = day+1;
         sum = weights[i];
        }
    }
    return day<days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
    auto minel = *max_element(weights.begin(),weights.end());
    int maxel = accumulate(weights.begin(),weights.end(),0);
    int low=minel;
    int high=maxel;
    int ans =0;
    while(low<=high){
        int mid = (low+high)/2;
        if(possible(weights,mid,days)){
            ans = mid;
            high = mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    }
};