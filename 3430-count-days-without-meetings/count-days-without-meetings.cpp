class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        int ans = days;
        sort(meetings.begin(),meetings.end());
        int l = 0;
        while(l<n){
            int start = meetings[l][0];
            int end = meetings[l][1];
            int r = l+1;
            while(r<n && meetings[r][0] <= end){
                end = max(end,meetings[r][1]);
                r++;
            }
            ans -= end-start+1;
            l = r;
        }
        return ans;
    }
};