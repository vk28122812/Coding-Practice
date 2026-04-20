class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();
        for(int i=1;i<n;i++){
            if(colors[0] != colors[i]){
                ans = max(ans, i);
            }
        }

        for(int i = n-2;i>=0;i--){
            if(colors[n-1] != colors[i]){
                ans = max(ans, n-1 - i);
                
            }
        }

        return ans;
    }
};