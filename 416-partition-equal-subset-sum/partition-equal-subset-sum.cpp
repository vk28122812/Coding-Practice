class Solution {
public:
    int dp[201][10001];

    bool targetSum(vector<int>&nums,int idx,int target){
        if(target<0)return 0;
        if(target==0)return 1;
        if(idx==nums.size())return target == 0;
        if(dp[idx][target] != -1)return dp[idx][target];
        bool pick = targetSum(nums,idx+1,target-nums[idx]);
        bool skip = targetSum(nums,idx+1,target);
        return dp[idx][target] = pick || skip;
    }
    bool canPartition(vector<int>& nums) {
        long total = 0;
        total = accumulate(nums.begin(),nums.end(), total);
        if(total%2)return 0;
        memset(dp,-1,sizeof(dp));
        return targetSum(nums,0,total/2);
    }
};