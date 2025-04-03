class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        int mx = nums[0];
        for(int i=1;i<n;i++){
            left[i] = mx;
            mx = max(mx, nums[i]);
        }
        long long ans = 0;
        mx = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(i>0)ans = max(ans, (left[i]-nums[i])*(long long)mx);
            mx = max(mx, nums[i]);
        }
        return ans;
    }
};