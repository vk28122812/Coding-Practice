class Solution {
public:
    bool isEnd(int i,vector<int>&v){
        return i==0 || i==(v.size()-1);
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            ans[i].resize(i+1);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    ans[i][j]=1;
                }else{
                    ans[i][j] = ans[i-1][j-1] +  ans[i-1][j];
                }
            }
        }
        return ans;
    }
};