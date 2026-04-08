class Solution {
    const long MOD = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(vector<int>&q: queries){
            int l = q[0], r = q[1], k = q[2], v = q[3];

            int idx = l;
            while(idx <= r){
                nums[idx] = (long(nums[idx]) * long(v)) % MOD;
                idx += k;
            }
        }

        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            ans = ans ^ nums[i];
        }

        return ans;
    }
};