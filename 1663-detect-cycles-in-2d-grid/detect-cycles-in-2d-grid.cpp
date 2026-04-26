class Solution {
    vector<vector<int>> vis;
public:
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool solve(vector<vector<char>>& mx, int pi, int pj, int i, int j, int c, int color) {
        vis[i][j] = color;
        for (auto d : dir) {
            int x = i + d.first;
            int y = j + d.second;
            if (x < 0 || y < 0 || x >= mx.size() || y >= mx[0].size() ||
                mx[x][y] != mx[i][j])
                continue;

            if(!vis[x][y]){
                if (solve(mx, i,j, x, y, c + 1, color))
                    return 1;   
            }else if( x != pi || y != pj){
                return c >= 4;
            }
        }
        return 0;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vis.resize(m, vector<int>(n,0));
        int c = 1;
        for (int i = 0; i < grid.size(); i += 1) {
            for (int j = 0; j < grid[0].size(); j += 1) {
                if(vis[i][j] != 0) continue;
                if (solve(grid, i, j, i, j, 1, c))
                    return 1;
                c++;
            }
        }
        return 0;
    }
};