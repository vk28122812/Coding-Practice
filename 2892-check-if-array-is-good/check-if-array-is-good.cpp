class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.begin()+n);

        int back = nums.back();
        if(back != n - 1) return 0;

        for(int i=0;i<n-1;i++){
            if(nums[i] != i+1) return 0;
        }

        

        return 1;
    }
};