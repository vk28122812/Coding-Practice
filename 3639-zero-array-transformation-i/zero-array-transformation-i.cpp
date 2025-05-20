class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>pre(n+1,0);
        for(auto&q:queries){
            pre[q[0]]-=1;
            pre[q[1]+1]+=1;
        }   
        // for(auto i:nums)cout<<i<<" ";cout<<endl;
        // for(auto i:pre)cout<<i<<" ";
        int s=0;
        for(int i=0;i<n;i++){
            s += pre[i];
            if( nums[i]+s>0 )return 0;
        }
        return 1;

        
    }
};