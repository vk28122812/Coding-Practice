class Solution {
public:
    bool isGood(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());


        unordered_map<int,int> mp;

        for(auto i:nums) mp[i]++;

        if(mp[mx] != 2) return 0;
        for(int i=1;i<mx;i++){
            if(mp[i] != 1) return 0;
        }

        return 1;   
    }
};