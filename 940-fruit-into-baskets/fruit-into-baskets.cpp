class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        deque<int> dq;
        dq.push_back(fruits[0]);
        int ans = 1;
        int runningFront = 0;
        int runningBack = 1;
        int totalRunning = 1;
        for(int i=1; i<fruits.size(); i++){
            if(fruits[i]==dq.back()){
                runningBack++;
                totalRunning++;
            }else if(fruits[i]==dq.front()){
                runningFront = runningBack;
                runningBack = 1;
                dq.push_back(dq.front());
                dq.pop_front();
                totalRunning++;
            }else{
                if(dq.size()==1){
                    dq.push_back(fruits[i]);
                    runningFront = runningBack;
                    runningBack = 1;
                    totalRunning++;
                }else{
                    runningFront = runningBack;
                    runningBack = 1;
                    dq.push_back(fruits[i]);
                    dq.pop_front();
                    totalRunning = runningFront + runningBack ;
                }
            }
            ans = max(ans,totalRunning);
        }
        return ans;
    }
};