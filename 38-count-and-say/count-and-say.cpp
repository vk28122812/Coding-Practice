class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string sub = countAndSay(n-1);
        string ans;
        int l = 0;
        while(l<sub.size()){
            int c = 0;
            int r = l;
            while(r<sub.size() && sub[l]==sub[r]){
                r++;
                c++;
            }
            ans += to_string(c);
            ans += sub[l];
            l = r;
        }
        return ans;   

    }
};