
class Solution {
public:
    const int mod = 1e9 + 7;
    long fastExponentiation(long x,long n){
        long ans = 1;
        while(n){
            if(n&1){
                ans = (ans*x)%mod;
            }
            x = (x*x)%mod;
            n /= 2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long even = ceil(n/2.0);
        long  odd = n/2;
        long ans1 = fastExponentiation(4,odd);
        long ans2 = fastExponentiation(5,even);
        return (ans1*ans2)%mod;
    }
};