const int mod = 1e9 + 7;
class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& mx, int i, int j, long s, int k) {

        if (i >= mx.size() || j >= mx[0].size())
            return 0;

        s = (s + mx[i][j]) % k;
        if (i == mx.size() - 1 && j == mx[0].size() - 1) {
            return s % k == 0;
        }
        int ans = 0;
        if (dp[i][j][s] != -1)
            return dp[i][j][s] % mod;

        ans = (ans + solve(mx, i, j + 1, s, k)) % mod;
        ans = (ans + solve(mx, i + 1, j, s, k)) % mod;
        return dp[i][j][s] = ans % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        dp.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(51, -1)));

        int ans = solve(grid, 0, 0, 0, k);
        return ans;
    }
};