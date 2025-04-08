class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int mp[101] = {};
        int notUnique = 0;
        for(const int&i : nums){
            mp[i]++;
        }
        for(int i:mp)if(i>1)notUnique++;
        int ans = 0;
        while(notUnique){
            for(int i=ans*3;i<min(ans*3+3,(int)nums.size());i++){
                if(mp[nums[i]]>1){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==1)notUnique--;
                }
            }
            ans++;
        }
        return ans;
    }
};