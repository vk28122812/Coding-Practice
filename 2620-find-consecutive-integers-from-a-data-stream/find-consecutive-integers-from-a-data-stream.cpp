class DataStream {
private:
    int k;
    int value;
    int c;

public:
    DataStream(int value, int k) {
        this->k = k;
        this->value = value;
        this->c = 0;
    }
    
    bool consec(int num) {
        if(value == num){
            c++;
        }else{
            c = 0;
        }
    
        return c >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */