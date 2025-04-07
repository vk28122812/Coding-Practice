class Solution {
public: 

    vector<pair<int,int>> dir{
        {1,0}, {0,1}, {-1,0}, {0,-1}
    };
    bool isPossible(vector<vector<int>>&grid,int mid){
        if(grid[0][0] > mid)return 0;
        queue<pair<int,int>>q;
        int  m= grid.size(), n= grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n));
        q.push({0,0});
        vis[0][0] = 1;
        while(q.size()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i==m-1 && j==n-1)return 1;
            for(auto&d:dir){
                int x = i + d.first;
                int y = j + d.second;
                if(x>=0 && x < m && y >= 0 && y < n && !vis[x][y] &&grid[x][y]<=mid){
                    q.push({x,y});
                    vis[x][y] = 1;
                }
            }
        }
        return 0;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        int low = 0, high = 2501;
        while(low <= high){
            int mid = (low+high)>>1;
            if(isPossible(grid,mid)){
                high = mid-1;
            }else low = mid+1;
        }
        return low;
    }
};