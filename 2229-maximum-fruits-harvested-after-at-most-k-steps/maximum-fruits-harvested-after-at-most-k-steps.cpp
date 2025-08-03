class Solution {
public:
    int maxN = 2 * (1e5) + 2;

    long getSum(vector<int>&arr,int l,int r){
        if(l>r)return 0;
        l = max(l,0);
        r = min(r,maxN-1);
        return long(arr[r]) - (l <= 0 ? 0 : arr[l-1]);
    }
    bool isPossible(vector<int>&tmp, int start, int k, long check){
        for(int l=0;l<=k; l++){
            int leftPos = start - l;
            if(leftPos < 0) break;
            int rem = k - 2 * l;
            if(rem >= 0){
                int rightPos = rem + start;
                if(getSum(tmp,leftPos, rightPos) >= check) return 1;
            }
        }
        for(int r=0;r<=k;r++){
            int rightPos = start + r;
            if(rightPos >= maxN) break;
            int rem = k - (rightPos - start)*2;
            if(rem >= 0){
                int leftPos = start - rem;
                if(getSum(tmp,leftPos, rightPos) >= check) return 1;
            }
        }
        return 0;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        long high = 0, low = 0;
        vector<int> tmp(maxN,0);
        for(auto f : fruits){
            tmp[f[0]] = f[1];
            high += f[1];
        }
        for(int i=1;i<maxN; i++)tmp[i] += tmp[i-1];

        int ans = low;
        while(low <= high){
            int mid = (high+low)>>1;
            if(isPossible(tmp, startPos, k, mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};