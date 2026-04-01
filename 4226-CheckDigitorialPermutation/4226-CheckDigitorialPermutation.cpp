// Last updated: 01/04/2026, 19:23:37
class Solution {
public:
    int fact(int n){
        if(n == 0) return 1;
        return n*fact(n - 1);
    }
    bool isDigitorialPermutation(int n) {
        string x = to_string(n);
        int sum = 0;
        while(n){
            sum += fact(n%10);
            n = n/10; 
        }
        string ans = to_string(sum);
        int y = x.size();
        for(int i = 0; i < ans.size();i++){
            if(x.find(ans[i]) != string::npos){
                auto it = x.find(ans[i]);
                x.erase(it,1);
            }
            else return false;
        }
        return ans.size() == y;
    }
};