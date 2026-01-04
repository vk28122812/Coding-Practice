class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(int i:nums){
            int s = 0;
            int c = 0;
            for(long j=1; j*j <= i; j++){
                if( i % j == 0){
                    int divisor = j;
                    int quotient = i/j;
                    c += 1;
                    s += divisor;

                    if( divisor != quotient){
                        c += 1;
                        s += quotient;
                    }
                }
            }
            if( c==4) ans += s;
        }

        return ans;
    }
};