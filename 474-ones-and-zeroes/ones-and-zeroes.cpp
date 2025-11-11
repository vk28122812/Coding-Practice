class Solution {
public:

    int dp[601][101][101];

    int solve(vector<string>&s,vector<pair<int,int>>&freq, int m,int n , int idx){
        if(idx>=s.size())return 0;
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        
        
        int pick = 0, notPick = 0;
        if(m -  freq[idx].first >= 0 && n - freq[idx].second >= 0){
            pick = 1 + solve(s,freq,m - freq[idx].first,n - freq[idx].second ,idx+1);
        }

        notPick = solve(s,freq,m,n,idx+1);
        
        return dp[idx][m][n] = max(pick, notPick);
    }


    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>> freq(strs.size(), {0,0});

        for (int i=0; i< strs.size(); i++){
            for(char ch: strs[i]){
                if(ch=='0')freq[i].first++;
                else freq[i].second++;
            }
        }
        
        return solve(strs,freq, m,n,0);
    }
};