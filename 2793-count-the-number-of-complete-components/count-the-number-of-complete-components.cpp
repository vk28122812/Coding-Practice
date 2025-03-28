class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&cmp,int u){
        vis[u] = 1;
        cmp.push_back(u);
        for(int v:adj[u]){
            if(vis[v])continue;
            dfs(adj,vis,cmp,v);
        }
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
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>cmp;
                dfs(adj,vis,cmp,i);
                components.push_back(cmp);
            }
        }
        int ans = 0 ;
        for(auto cmp:components){   
            int v = cmp.size();
            int e = 0;
            for(int c:cmp){
                e += degree[c];
            }
            if( v * (v-1) == e ){
                ans++;
            }
        }
        return ans;
    }
};