// Last updated: 01/04/2026, 19:25:19
class Solution {
public:
    bool possible(vector<int>& bloomDay,int day, int m, int k){
    int n = bloomDay.size();
    int cnt =0;
    int boq =0;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=day){
            cnt++;
        }
        else{
        boq =boq+cnt/k;
        cnt =0;
        }
    }
   boq+= cnt/k;
   if(boq>=m) {
    return true;
   }
   else{
    return false;
   }
   }
    int minDays(vector<int>& bloomDay, int m, int k) {
    long long  val = 1ll*m* k;
    int n = bloomDay.size();
     if(val>n){
        return -1;
     }
     int minel = INT_MAX;
     int maxel = INT_MIN;
     for(int i=0;i<n;i++){
        minel = min(minel,bloomDay[i]);
        maxel = max(maxel,bloomDay[i]);
     }
    int low= minel;
    int high = maxel;
    int ans =-1;
    while(low<=high){
    int mid = (low+high)/2;
    if(possible(bloomDay,mid,m,k)){
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