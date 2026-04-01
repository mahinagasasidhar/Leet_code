// Last updated: 01/04/2026, 19:26:19
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left;i <= right; i++){
            int num = i;
            bool flag = true;
            while(num){
                int l = num % 10;
                num = num/10;
                if(l == 0) flag = false;
                if(flag && i % l) flag = false;
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};