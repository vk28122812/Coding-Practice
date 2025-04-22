class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0;
        unordered_set<int> st;
        int runningSum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            while(st.count(nums[i])){
                runningSum -= nums[l];
                st.erase(nums[l]);
                l++;
            }
            runningSum += nums[i];
            st.insert(nums[i]);
            ans = max(ans, runningSum);
        }
        return ans;
    }
};