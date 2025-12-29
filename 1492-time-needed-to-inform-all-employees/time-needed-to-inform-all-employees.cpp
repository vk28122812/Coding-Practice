class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<int>& cost, int u) {
        int ans = 0;
        for (int v : adj[u]) {
            ans = max(ans, cost[u] + dfs(adj, cost, v));
        }
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if(i == headID)continue;
            adj[manager[i]].push_back(i);
        }
        return dfs(adj, informTime, headID);
    }
};