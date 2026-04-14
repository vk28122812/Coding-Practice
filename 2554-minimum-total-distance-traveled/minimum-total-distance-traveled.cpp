class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(vector<int>&robot, vector<int>&factory, int robotIdx, int factoryIdx){
        if(robotIdx >= robot.size()) return 0;
        if(factoryIdx >= factory.size()) return LONG_MAX;
        if(dp[robotIdx][factoryIdx] != -1) return dp[robotIdx][factoryIdx];
        long pick = LONG_MAX, skip = LONG_MAX;
        long ans = LONG_MAX;
        
            
        pick = solve(robot, factory, robotIdx + 1, factoryIdx+1);
        
        skip = solve(robot, factory, robotIdx, factoryIdx + 1);
        if(pick != LONG_MAX){
            ans = min(ans, pick + abs(robot[robotIdx] - factory[factoryIdx]));
        }
        if(skip != LONG_MAX){
            ans = min(ans, skip);
        }
        
        return dp[robotIdx][factoryIdx] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> fact;
        for(auto i : factory){
            for(int j=0;j<i[1]; j++){
                fact.push_back(i[0]);
            }
        }

        sort(robot.begin(), robot.end());
        sort(fact.begin(), fact.end());
        dp.resize(robot.size(), vector<long long>(fact.size(), -1));
        return solve(robot,fact,0,0);
    }
};