class DataStream {
public:
    int sz,p;
    int ok = 0;
    DataStream(int value, int k) {
        sz = k;
        p = value;
    }
    
    bool consec(int num) {
        if(num==p){
            ok++;
        }
        else{
            ok = 0;
        }
        if(ok>=sz){
            return true;
        }
        else return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */