class Solution {
public: 

    vector<pair<int,int>> dir{
        {1,0}, {0,1}, {-1,0}, {0,-1}
    };
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0,0,});
        while(pq.size()){
            int w = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            if(x==m-1 && y==n-1){
                return w;
            }
            if(vis[x][y])continue;
            vis[x][y] = 1;

            for(auto&d:dir){
                int i = x + d.first;
                int j = y + d.second;
                if(i < 0 || j < 0 || i==m || j==n )continue;
                pq.push({max(w,grid[i][j]), i,j});

            }
        }
        return -1;
    }
};