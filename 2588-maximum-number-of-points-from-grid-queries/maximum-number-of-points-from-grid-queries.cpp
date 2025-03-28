class Solution {
public:
    #define p pair<int,int> 

    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool isValid(int x,int y,vector<vector<int>>&mx){
        return x >= 0 && y >=0 && x < mx.size() && y < mx[0].size();
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans(n,-1);
        vector<p>Queries;
        for(int i=0;i<n;i++){
            Queries.push_back({queries[i],i});
        }
        sort(Queries.begin(),Queries.end());
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size()));
        priority_queue<pair<int,p>> pq;
        pq.push({-grid[0][0], {0,0}});
        vis[0][0] = 1;
        int tmp = 0;
        for(auto Q:Queries){
            int q = Q.first;
            int idx = Q.second;
            // cout << q << " "<<idx<<"    ";
            while(pq.size()){
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                int val = grid[x][y];
                // cout << x <<" "<<y<<" "<<val<<"      ";
                if(val < q){
                    tmp++;
                    pq.pop();
                }else break;
                for(auto d:dir){
                    int nextX = x + d.first;
                    int nextY = y + d.second;
                    if(isValid(nextX,nextY,grid) && !vis[nextX][nextY]){
                        vis[nextX][nextY] = 1;
                        pq.push({-grid[nextX][nextY],{nextX,nextY}});
                    }
                }
            }
            // cout <<endl;
            ans[idx] = tmp;
        }
        return ans;
    }
};