class Solution {
public:
    vector<int> bfs(vector<vector<int>>&adj,vector<int>&vis,int u){
        vector<int> cmp;
        cmp.push_back(u);
        queue<int> q;
        q.push(u);
        vis[u] = 1;
        while(q.size()){
            int v = q.front(); q.pop();
            for(int next:adj[v]){
                if(vis[next])continue;
                cmp.push_back(next);
                q.push(next);
                vis[next] = 1;
            }
        }
        return cmp;
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
                components.push_back(bfs(adj,vis,i));
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