class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    ans = max(ans, (nums[i] - nums[j])*(long long)nums[k]);
                }
            }
        }
        return ans;
    }
};