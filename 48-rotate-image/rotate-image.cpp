class Solution {
public:
    void rotate(vector<vector<int>>& mx) {
        int n = mx[0].size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mx[i][j], mx[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(mx[i][j], mx[i][n-1-j]);
            }
        }
        
    }
};