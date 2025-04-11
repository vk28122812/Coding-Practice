class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low;i<=high;i++){
            int d = log10(i)+1;
            int copy = i;
            if(d%2==0){
                int s=0;
                for(int i=0;i<d/2;i++){
                    s += copy%10;
                    copy/=10;
                }
                for(int i=0;i<d/2;i++){
                    s -= copy%10;
                    copy/=10;
                }
                if(s==0)ans++;
            }
        }
        return ans;
    }
};