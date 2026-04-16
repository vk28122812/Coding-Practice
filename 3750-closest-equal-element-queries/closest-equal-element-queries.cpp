class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> tmp(n, INT_MAX);
        unordered_map<int,pair<int,int>> mp;


        for(int i=0;i<n;i++){
            if(!mp.count(nums[i])){
                mp[nums[i]] = {i,i};
            }else{
                int l = mp[nums[i]].first, r = mp[nums[i]].second;

                int distanceFromLeft = n - i + l;
                int distanceFromRight = i - r;

                tmp[i] = min(distanceFromLeft, distanceFromRight);

                tmp[l] = min( tmp[l], distanceFromLeft);
                tmp[r] = min( tmp[r], distanceFromRight);

                mp[nums[i]].second = i;
            }
        }


        vector<int> ans;

        for(int q: queries){
            if(tmp[q] == INT_MAX){
                ans.push_back(-1);
            }else{
                ans.push_back(tmp[q]);
            }
        }

        return ans;
    }
};