class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int mask=0;mask<(1<<n);mask++){
            int XOR = 0;

            for(int i=0;i<n;i++){
                if(mask & (1<<i))XOR ^= nums[i];
            }

            total += XOR;
        }
        return total;
    }
};