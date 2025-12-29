class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>&adj, vector<int>&vis,vector<int>&path, int u ){
        path.push_back(u);
        vis[u] = 1;
        for(int v:adj[u]){
            if(!vis[v]){
                dfs(adj,vis,path,v);
            }
        }
        if(u == adj.size()-1){
            ans.push_back(path);
        }
        path.pop_back();
        vis[u] = 0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>vis(v,0);
        vector<int>path;
        dfs(graph, vis, path, 0 );
        return ans;
    }
};