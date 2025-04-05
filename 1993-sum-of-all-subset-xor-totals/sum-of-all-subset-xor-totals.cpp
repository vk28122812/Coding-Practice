class Solution {
public:
    void solve(vector<int>&nums,int idx,int XOR,int&ans){
        if(idx==nums.size()){
            ans += XOR;
            return;
        }
        solve(nums,idx+1,XOR ^ nums[idx],ans);
        solve(nums,idx+1,XOR,ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        solve(nums,0,0,ans);
        return ans;
    }
};