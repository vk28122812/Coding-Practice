class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int l = -1;
        double prod = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                l = i;
                prod = 1;
            } else {
                if (nums[i] > 0) {
                    prod *= 1;
                } else {
                    prod *= -1;
                }
                if (prod == 1) {
                    ans = max(ans, i - l);
                }
            }
        }
        prod = 1;
        l = n;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                l = i;
                prod = 1;
            } else {
                if (nums[i] > 0) {
                    prod *= 1;
                } else {
                    prod *= -1;
                }
                if (prod == 1) {
                    ans = max(ans, l - i);
                }
            }
        }

        return ans;
    }
};