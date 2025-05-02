class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n), right(n);
        int last = -1;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='L'){
                last = -1;
            }else if(dominoes[i]=='R'){
                last = i;
            }else if(dominoes[i]=='.' && last != -1){
                right[i] = i-last;
            }
        }
        last = -1;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='R'){
                last = -1;
            }else if(dominoes[i]=='L'){
                last = i;
            }else if(dominoes[i]=='.' && last != -1){
                left[i] = last - i;
            }
        }
        for(int i=0;i<n;i++){
            if(dominoes[i]=='.'){
                if(left[i] && right[i]){
                    if(left[i]>right[i]){
                        dominoes[i] = 'R';
                    }else if(left[i]<right[i]){
                        dominoes[i] = 'L';
                    }
                }else if(left[i]){
                        dominoes[i] = 'L';
                }else if(right[i]){
                        dominoes[i] = 'R';
                }
            }
        }
        // for(auto i:right)cout<<i<<" ";cout<<endl;
        // for(auto i:left)cout<<i<<" ";cout<<endl;
        return dominoes;
    }
};