class Solution {
public:
    bool bfs(vector<vector<int>>&adj,vector<int>&degree,vector<int>&vis,int u){
        queue<int> q;
        q.push(u);
        vis[u] = 1;
        int m = 1;
        int e = degree[u];
        while(q.size()){
            int v = q.front(); q.pop();
            for(int next:adj[v]){
                if(vis[next])continue;
                m++;
                e+=degree[next];
                q.push(next);
                vis[next] = 1;
            }
        }
        return e == m*(m-1);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> degree(n,0), vis(n,0);
        vector<vector<int>>adj(n), components;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        int ans = 0 ;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans += bfs(adj,degree,vis,i);
            }
        }
        return ans;
    }
};