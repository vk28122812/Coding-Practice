struct pair_hash{
    size_t operator()(const pair<int,int>&p) const{
        return hash<int>()(p.first) ^ hash<int>()(p.second << 1);
    }
};
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& input) {
        int ans = 0;
        int n = input.size();
        unordered_map<pair<int,int>,int,pair_hash>mp;
        for(auto&i:input){
            mp[{min(i[0],i[1]), max(i[0],i[1])}] += 1;
        }
        for(auto&i:mp){
            if(i.second > 1){
                ans += (i.second) * (i.second-1) / 2;
            }
        }
        return ans;
    }
};