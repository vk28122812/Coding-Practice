class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int arr[101] = {};
        for(int i:nums)arr[i] = 1;
        for(int i=0;i<k;i++){
            if(arr[i])return -1;
        }
        return accumulate(arr+k+1, arr+101,0);
    }
};