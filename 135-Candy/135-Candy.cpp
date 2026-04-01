// Last updated: 01/04/2026, 19:27:57
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> larray(n);
        larray[0] = 1; 
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                larray[i] = larray[i - 1] + 1;
            }
            else{
                larray[i] = 1;
            }
        }
        int sum = max(larray[n-1],1);
        int prev = 1;
        int curr = 0;
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                curr = prev + 1;
            }
            else{
                curr = 1;
            }
            prev = curr;
            sum += max(curr,larray[i]);
        }
        return sum;
    }
};