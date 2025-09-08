class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int>dp;
    int solve(string&s,int idx){
        if(idx >= s.size()){
            return 1;
        }
        if(dp[idx] != -1)return dp[idx];
        int curr = 0, next = 0;
        int ans = 0;
        if(isdigit(s[idx])){
            curr = s[idx] - '0';
            if(curr==0)return 0;
            ans += solve(s,idx+1);
            ans %= mod;
            if(idx+1 != s.size()){
                if(isdigit(s[idx+1])){
                    next = s[idx+1] - '0';
                    if(curr * 10 + next <= 26){
                        ans += solve(s,idx+2);
                        ans %= mod;
                    }
                }else{
                    for(int i=1;i<=9;i++){
                        if(curr * 10 + i <= 26){
                            ans += solve(s,idx+2);
                            ans %= mod;
                        }   
                    }
                }
            }
        }else{
            for(int curr=1;curr<=9;curr++){
                ans += solve(s,idx+1);
                ans %= mod;
                if(idx+1 != s.size()){
                    if(isdigit(s[idx+1])){
                        next = s[idx+1] - '0';
                        if(curr * 10 + next <= 26){
                            ans += solve(s,idx+2);
                            ans %= mod;
                        }   
                    }else{
                        for(int i=1;i<=9;i++){
                            if(curr * 10 + i <= 26){
                                ans += solve(s,idx+2);
                                ans %= mod;
                            }   
                        }
                    }    
                }
            }
        }
        return dp[idx] = ans%mod;
    }
    int numDecodings(string s) {
        dp.resize(s.size()+1,-1);
        return  solve(s,0);
    }
};