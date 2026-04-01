// Last updated: 01/04/2026, 19:23:33
class Solution {
public:
    int countCommas(int n) {      
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            int x = i;
        int count = 0;
        while(x){
        x /= 10;
        count++;
    } 
          if(count > 3) cnt += (count-1)/3;  
        }
        return cnt;
    }
};