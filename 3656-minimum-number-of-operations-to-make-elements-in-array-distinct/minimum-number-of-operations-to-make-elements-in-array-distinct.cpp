class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(const int&i : nums){
            mp[i]++;
        }
        for(const int&i : nums){
            if(mp.count(i) && mp[i]==1)mp.erase(i);
        }
        int ans = 0;
        while(mp.size()){
            cout << mp.size()<<" ";
            for(int i=ans*3;i<min(ans*3+3,(int)nums.size());i++){
                if(mp.count(nums[i])){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==1)mp.erase(nums[i]);
                }
            }
            ans++;
        }
        return ans;
    }
};