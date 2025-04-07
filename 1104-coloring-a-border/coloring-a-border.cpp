class Solution {
public:
    vector<pair<int,int>>dir{
        {0,1},{1,0},{-1,0},{0,-1}
    };
    void solve(vector<vector<int>>&grid,vector<vector<int>>&vis,int i,int j,int col){
        vis[i][j] = 1;
        bool isBoundary = (i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1);
        bool shared = 0;
        for(auto&d:dir){
            int x = i+d.first;
            int y = j+d.second;
            if(x < 0 || y < 0 || x==grid.size() || y==grid[0].size())continue;
            if(vis[x][y])continue;
            if(grid[x][y] != grid[i][j]){
                shared = 1;
            }else{
                solve(grid,vis,x,y,col);
            }
        }
        if(isBoundary || shared)grid[i][j] = col;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        solve(grid,vis,row,col,color);
        return grid;
    }
};