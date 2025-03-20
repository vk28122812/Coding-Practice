class DSU{
public:
    vector<int> link,size,cost;
    int V;
    DSU(int n){
        V = n;
        cost.resize(n,INT_MAX);
        link.resize(n); size.resize(n);

        for(int i=0;i<n;i++){
            size[i] = 1;
            link[i] = i;
        }
    }

    int find(int x){
        while(x != link[x])x = link[x];
        return x;
    }
    bool tryUnite(int a,int b){
        a = find(a);
        b = find(b);
        if(a==b)return 0;
        if(size[a]<size[b])swap(a,b);
        size[a] += size[b];
        link[b] = a;
        return 1;
    }
};
class Solution {
public:

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for(auto e:edges){
            dsu.tryUnite(e[0],e[1]);
        }
        for(auto e:edges){
            int root = dsu.find(e[0]);
            dsu.cost[root] &= e[2];
        }
        vector<int>ans;
        for(auto q:query){
            int u = q[0], v = q[1];
            if(dsu.find(u) != dsu.find(v))ans.push_back(-1);
            else ans.push_back(dsu.cost[dsu.find(u)]);
        }
        return ans;
    }
};