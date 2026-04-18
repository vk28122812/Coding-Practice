class Solution {
public:
    int mirrorDistance(int n) {
        int reverse = 0;
        int tmp = n;

        while(tmp){
            int rem = tmp % 10;
            reverse = reverse*10 + rem;
            tmp /= 10;
        }

        return abs(n - reverse);
    }
};