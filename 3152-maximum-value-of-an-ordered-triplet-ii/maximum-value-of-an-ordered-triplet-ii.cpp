class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        int mx = nums[0];
        for(int i=1;i<n;i++){
            left[i] = mx;
            mx = max(mx, nums[i]);
        }
        mx = nums[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = mx;
            mx = max(mx, nums[i]);
        }
        long long ans = 0;
        for(int i=1;i<n-1;i++){
            ans = max(ans, (left[i]-nums[i])*(long long)right[i]);
        }
        return ans;
    }
};