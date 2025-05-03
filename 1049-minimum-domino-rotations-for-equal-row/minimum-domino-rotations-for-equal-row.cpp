class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> mp;
        int n = tops.size();
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                mp[tops[i]]++;
            }else{
                mp[tops[i]]++;
                mp[bottoms[i]]++;
            }
        }
        int tmp = 0;
        for(auto i:mp){
            if(i.second == n)tmp=i.first;
        }
        if(tmp==0)return -1;
        int t = 0, b = 0;
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                continue;
            }
            if(tops[i]==tmp)t++;
            if(bottoms[i]==tmp)b++;
        }
        return min(t,b);
    }
};