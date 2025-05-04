class Solution {
public:
  
    int numEquivDominoPairs(vector<vector<int>>& input) {
        int ans = 0;
        int n = input.size();
        for(int i=0; i<n; i++){
            if(input[i][0] > input[i][1]){
                swap(input[i][0],input[i][1]);
            }
        }
        sort(input.begin(),input.end());
        int l=0;
        while(l<n){
            int r=l+1;
            while(r<n && input[l]==input[r]){
                r++;
            }
            int p = r-l;
            ans += (p)*(p-1)/2;
            l = r;
        }
        return ans;
    }
};