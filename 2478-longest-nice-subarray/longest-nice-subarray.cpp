class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        int mask = 0;
        int idx = 0;
        for(int i=0;i<nums.size();i++){
            while(mask & nums[i]){
                mask ^= nums[idx];
                idx++;
            }
            mask ^= nums[i];
            ans = max(ans, i-idx+1);
        }
        return ans;
    }
};