class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> mp;
        for(int i: a)mp[i]++;
        for(int i: b)mp[i]--;

        int mn = INT_MAX;
        vector<int> toSwap;
        for(auto [k,v]: mp){
            if(v & 1)return -1;
            for(int i=0;i<abs(v)/2; i++){
                toSwap.push_back(k);
            }
            mn = min(mn, k);
        }
    
        sort(toSwap.begin(), toSwap.end());

        long ans = 0;
        for(int i=0;i<toSwap.size()/2;i++){
            ans += min(2*mn, toSwap[i]);
        }
        return ans;

    }
};