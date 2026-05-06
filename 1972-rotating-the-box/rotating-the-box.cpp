class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();

        vector<vector<char>> mx(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mx[j][m-1-i] = boxGrid[i][j];
            }
        }

        for (int col = 0; col < m; col++) {
            int empty = n-1;
            for(int row=n-1;row >=0;row--){
                if(mx[row][col] == '*'){
                    empty = row - 1;
                }else if(mx[row][col] == '#'){
                    swap(mx[row][col], mx[empty][col]);
                    empty--;
                }
                
            }
        }

        return mx;
    }
};