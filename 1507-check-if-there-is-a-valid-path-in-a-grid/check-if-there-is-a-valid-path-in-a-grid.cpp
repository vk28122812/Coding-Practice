class Solution {
    unordered_map<int, vector<pair<int, int>>> dirMap{
        {1, {{0, 1}, {0, -1}}},
          {2, {{1, 0}, {-1, 0}}},
        {3, {{0, -1}, {1, 0}}},  
        {4, {{1, 0}, {0, 1}}},
    
        {5, {{-1, 0}, {0, -1}}}, 
        {6, {{-1, 0}, { 0, 1}}}};

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        while (q.size()) {
            auto ft = q.front();
            q.pop();
            int f = ft.first, s = ft.second;
            if (f == m - 1 && s == n - 1)
                return 1;
            int curr = grid[f][s];

            for (auto d : dirMap[curr]) {
                int x = f + d.first;
                int y = s + d.second;
                if (x < 0 || y < 0 || x >= m || y >= n || vis[x][y])
                    continue;

                int next = grid[x][y];
                bool nextAllowed = false;

                for (auto bck : dirMap[next]) {
                    if (bck.first + x == f && bck.second + y == s) {
                        nextAllowed = true;
                        break;
                    }
                }
                if (nextAllowed) {
                    q.push({x, y});
                    vis[x][y] = 1;
                }
            }
        }

        return 0;
    }
};