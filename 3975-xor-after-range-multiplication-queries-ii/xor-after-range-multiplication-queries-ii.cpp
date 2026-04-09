class Solution {
    const int MOD = 1e9 + 7;
public:

    int pow(long x, long y) {
            long res = 1;
            for (; y; y >>= 1) {
                if (y & 1) {
                    res = res * x % MOD;
                }
                x = x * x % MOD;
            }
            return res;
        }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int, vector<vector<int>>> smallKMap;
        int blockSize = ceil(sqrt(nums.size()));


        for(auto q: queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            if(k >= blockSize){
                for(int idx = l; idx <= r; idx+=k){
                    nums[idx] = (long(nums[idx]) * v) % MOD;
                }
            }else{
                smallKMap[k].push_back(q);
            }
        }

        for( auto [k, allQueries] : smallKMap) {

            vector<long long> diff(nums.size() + blockSize, 1);

            for( auto q : allQueries){
                int l = q[0];
                int r = q[1];
                int v = q[3];
                
                diff[l] = (diff[l] * v) % MOD;

                int steps = (r - l) / k;

                int next = l + (steps + 1) * k;

                diff[next] = (diff[next] * pow(v, MOD - 2 ) )% MOD;
            }

            for( int i = 0; i<= nums.size(); i++){
                if(i - k >= 0){
                    diff[i] = (diff[i] * diff[i-k])%MOD;
                }
            }

            for(int i = 0;i< nums.size() ; i++){
                nums[i] = (long(nums[i]) * diff[i]) % MOD;
            }

        }


        int result = 0;

        for(int i = 0; i< nums.size(); i++){
            result =  result ^ nums[i];
        }


        return result;

        
    }
};