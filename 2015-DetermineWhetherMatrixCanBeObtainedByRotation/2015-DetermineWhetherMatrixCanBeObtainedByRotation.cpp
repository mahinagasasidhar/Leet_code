// Last updated: 01/04/2026, 19:25:02
class Solution {
public:
    vector<int> column(vector<vector<int>>& target,int c,int n){
        vector<int> temp;;
        for(int i=0;i<n;i++) temp.push_back(target[i][c]);
        return temp;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        if(mat == target) return 1;
        bool flag = true;
        for(int i=0;i<n;i++){
            if(mat[i] != column(target,n-i-1,n)){
                flag = false;
                break;
            }
        }
        if(flag) return true;
        else flag = true;
        for(int i=0;i<n;i++){
            vector<int> revrow = target[n-i-1];
            reverse(revrow.begin(),revrow.end());
            if(mat[i] != revrow){
                flag = false;
                break;
            }
        }
        if(flag) return true;
        else flag = true;
        for(int i=0;i<n;i++){
            vector<int> revcolumn = column(target,i,n);
            reverse(revcolumn.begin(),revcolumn.end());
            if(mat[i] != revcolumn){
                flag = false;
                break;
            }
        }
        return flag;
    }
};