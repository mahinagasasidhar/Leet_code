// Last updated: 01/04/2026, 19:26:04
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int n = piles.size();
       int r = *max_element(piles.begin(),piles.end());
       int l = 1;
       int mid;
       while(l < r){
        int ans = 0;
        mid = (l+r)/2;
        for(int i = 0;i < n;i++){
            if(piles[i] <= mid) ans++;
            else{
                ans += (piles[i] + mid - 1)/mid;
            }
        }
        if(ans > h) l = mid+1;
        else r = mid;
       }  
       return l;
    }
};