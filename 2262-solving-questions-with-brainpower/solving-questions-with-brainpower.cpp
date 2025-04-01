class Solution {
    vector<long long> dp;
public: 
    long long solve(vector<vector<int>>&ques,int idx){
        if(idx >= ques.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        long long pick = ques[idx][0] + solve(ques,idx + ques[idx][1] + 1);
        long long skip = solve(ques,idx + 1);
        return dp[idx] = max(pick,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size(), -1);
        return solve(questions, 0);
    }
};